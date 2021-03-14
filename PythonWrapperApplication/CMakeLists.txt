set(CMAKE_INCLUDE_CURRENT_DIR ON)

message("**** configuring KratosPythonWrapperApplication ****")

################### PYBIND11
include(pybind11Tools)

include_directories( ${CMAKE_SOURCE_DIR}/kratos )

## KratosPythonWrapperApplication Core sources
file(GLOB_RECURSE KRATOS_PYTHON_WRAPPER_APPLICATION_CORE
     ${CMAKE_CURRENT_SOURCE_DIR}/python_wrapper_application.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/python_wrapper_application_variables.cpp
)

if(${KRATOS_BUILD_TESTING} MATCHES ON)
    file(GLOB_RECURSE KRATOS_PYTHON_WRAPPER_APPLICATION_TESTING_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tests/cpp_tests/*.cpp)
endif(${KRATOS_BUILD_TESTING} MATCHES ON)

## KratosPythonWrapperApplication python interface sources
file(GLOB_RECURSE KRATOS_PYTHON_WRAPPER_APPLICATION_PYTHON_INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/custom_utilities/python_object_cpp_wrapper_utility.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/custom_python/*.cpp
)

add_library(KratosPythonWrapperCore SHARED ${KRATOS_PYTHON_WRAPPER_APPLICATION_CORE} ${KRATOS_PYTHON_WRAPPER_APPLICATION_TESTING_SOURCES})
target_link_libraries(KratosPythonWrapperCore PUBLIC KratosCore)
set_target_properties(KratosPythonWrapperCore PROPERTIES COMPILE_DEFINITIONS "PYTHON_WRAPPER_APPLICATION=EXPORT,API")

# define library Kratos which defines the basic python interface
pybind11_add_module(KratosPythonWrapperApplication MODULE THIN_LTO ${KRATOS_PYTHON_WRAPPER_APPLICATION_PYTHON_INTERFACE})
target_link_libraries(KratosPythonWrapperApplication PRIVATE KratosPythonWrapperCore)
set_target_properties(KratosPythonWrapperApplication PROPERTIES PREFIX "")

# changing the .dll suffix to .pyd (Windows)
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
     set_target_properties(KratosPythonWrapperApplication PROPERTIES SUFFIX .pyd)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

# changing the .dylib suffix to .so (OS X)
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
     set_target_properties(KratosPythonWrapperApplication PROPERTIES SUFFIX .so)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

# Set batch size in the unity build
IF(CMAKE_UNITY_BUILD MATCHES ON)
    set_target_properties(KratosPythonWrapperCore PROPERTIES UNITY_BUILD_BATCH_SIZE ${KRATOS_UNITY_BUILD_BATCH_SIZE})
    set_target_properties(KratosPythonWrapperApplication PROPERTIES UNITY_BUILD_BATCH_SIZE ${KRATOS_UNITY_BUILD_BATCH_SIZE})
ENDIF(CMAKE_UNITY_BUILD MATCHES ON)

# Add to the KratosMultiphisics Python module
kratos_python_install(${INSTALL_PYTHON_USING_LINKS} ${CMAKE_CURRENT_SOURCE_DIR}/PythonWrapperApplication.py KratosMultiphysics/PythonWrapperApplication/__init__.py )

# Install python files
get_filename_component (CURRENT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
kratos_python_install_directory(${INSTALL_PYTHON_USING_LINKS} ${CMAKE_CURRENT_SOURCE_DIR}/python_scripts KratosMultiphysics/${CURRENT_DIR_NAME} )

# Kratos Testing. Install everything except sources to ensure that reference and configuration files are copied.
if(${INSTALL_TESTING_FILES} MATCHES ON )
    get_filename_component (CURRENT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests DESTINATION applications/${CURRENT_DIR_NAME}
        PATTERN "*.git" EXCLUDE
        PATTERN "*.c" EXCLUDE
        PATTERN "*.h" EXCLUDE
        PATTERN "*.cpp" EXCLUDE
        PATTERN "*.hpp" EXCLUDE
  )
endif(${INSTALL_TESTING_FILES} MATCHES ON)

# Install targets
install(TARGETS KratosPythonWrapperCore DESTINATION libs )
install(TARGETS KratosPythonWrapperApplication DESTINATION libs )
