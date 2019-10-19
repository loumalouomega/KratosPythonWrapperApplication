set(CMAKE_INCLUDE_CURRENT_DIR ON)

message("**** configuring KratosPythonWrapperApplication ****")

include_directories( ${CMAKE_SOURCE_DIR}/kratos )

# generate variables with the sources
set( KRATOS_PYTHON_WRAPPER_APPLICATION_SOURCES
     ${CMAKE_CURRENT_SOURCE_DIR}/python_wrapper_application.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/python_wrapper_application_variables.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/custom_python/python_wrapper_python_application.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/custom_python/add_custom_utilities_to_python.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/custom_utilities/python_object_cpp_wrapper_utility.cpp
)

# define library Kratos which defines the basic python interface
pybind11_add_module(KratosPythonWrapperApplication MODULE THIN_LTO ${KRATOS_PYTHON_WRAPPER_APPLICATION_SOURCES})
target_link_libraries(KratosPythonWrapperApplication KratosCore )
set_target_properties(KratosPythonWrapperApplication PROPERTIES PREFIX "")

if(USE_COTIRE MATCHES ON)
    cotire(KratosPythonWrapperApplication)
endif(USE_COTIRE MATCHES ON)

install(TARGETS KratosPythonWrapperApplication DESTINATION libs )

# changing the .dll suffix to .pyd (Windows)
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
     set_target_properties(KratosPythonWrapperApplication PROPERTIES SUFFIX .pyd)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

# changing the .dylib suffix to .so (OS X)
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
     set_target_properties(KratosPythonWrapperApplication PROPERTIES SUFFIX .so)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

# install the python files
if(${INSTALL_PYTHON_FILES} MATCHES ON)
  get_filename_component (CURRENT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
  install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/python_scripts DESTINATION applications/${CURRENT_DIR_NAME}  FILES_MATCHING PATTERN "*.py"  PATTERN ".svn" EXCLUDE)
endif(${INSTALL_PYTHON_FILES} MATCHES ON)

file(WRITE "${CMAKE_CURRENT_SOURCE_DIR}/PythonWrapperApplication.py" "from __future__ import print_function, absolute_import, division #makes KratosMultiphysics backward compatible with python 2.6 and 2.7\nimport KratosMultiphysics as KM\nfrom KratosPythonWrapperApplication import *\napplication = KratosPythonWrapperApplication()\napplication_name = \"KratosPythonWrapperApplication\"\napplication_folder = \"${CMAKE_CURRENT_SOURCE_DIR}\"\n\nKM._ImportApplicationAsModule(application, application_name, application_folder, __path__)")

# Add to the KratosMultiphisics Python module
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/PythonWrapperApplication.py" DESTINATION "KratosMultiphysics/PythonWrapperApplication" RENAME "__init__.py")
