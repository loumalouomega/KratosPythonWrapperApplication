# KratosPythonWrapperApplication
This repository contains the PythonWrapperApplication source files for KratosMultiphysics

Add the following lines to the applications/CMakeLists.txt according to the existent structure.

~~~sh
PYTHON_WRAPPER_APPLICATION;\ 
~~~

and

~~~sh
if(${PYTHON_WRAPPER_APPLICATION} MATCHES ON) 
  add_subdirectory(PythonWrapperApplication) 
endif(${PYTHON_WRAPPER_APPLICATION} MATCHES ON) 
~~~
