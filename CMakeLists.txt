set(CMAKE_INCLUDE_CURRENT_DIR ON)

#echo of user defined options
SET(LIST_OF_APPS "\
PYTHON_WRAPPER_APPLICATION;\
")

message( " ")
message( " ")
message( "***** LIST OF KRATOS EXTERNAL APPLICATIONS THAT ARE GOING TO BE COMPILED: *****")
message( " ")

FOREACH(APP ${LIST_OF_APPS})
IF(${${APP}} MATCHES ON)
message("                ${APP} - ${${APP}}")
ENDIF(${${APP}} MATCHES ON)
ENDFOREACH()
message( " ")
message( "**********************************************************************")
message( " ")

message( "********** LIST OF KRATOS APPLICATIONS THAT ARE SET TO OFF: **********")
message( " ")
FOREACH(APP ${LIST_OF_APPS})
IF(${${APP}} MATCHES OFF)
message("                ${APP} - ${${APP}}")
ENDIF(${${APP}} MATCHES OFF)
ENDFOREACH()
message( " ")
message( "**********************************************************************")

message( " ")
message( " ")

#include subdirectories for compilation
if(${PYTHON_WRAPPER_APPLICATION} MATCHES ON)
  add_subdirectory(PythonWrapperApplication)
endif(${PYTHON_WRAPPER_APPLICATION} MATCHES ON)

# get_property(inc_dirs DIRECTORY PROPERTY INCLUDE_DIRECTORIES)
# message("applications subdir inc_dirs = ${inc_dirs}")
