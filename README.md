# KratosPythonWrapperApplication
This repository contains the PythonWrapperApplication source files for KratosMultiphysics

## How to use

his now allows to directly import from python, so I added the code of a "Main" that uses the analysis stage. Now we can run the simulation (without any additional modification) directly from C++. I added a main equivalent to the one of the structural, so:

(The interface on python in only for testing, can be removed, the final objective is to run everything from C++)

~~~py
import KratosMultiphysics
import KratosMultiphysics.PythonWrapperApplication as PWA
PWA.PythonObjectCppWrapperUtility.RunStructuralAnalysisStage("ProjectParameters.json")
~~~

is equal to:

~~~py
import KratosMultiphysics
from KratosMultiphysics.StructuralMechanicsApplication.structural_mechanics_analysis import StructuralMechanicsAnalysis

"""
For user-scripting it is intended that a new class is derived
from StructuralMechanicsAnalysis to do modifications
"""

if __name__ == "__main__":

    with open("ProjectParameters.json",'r') as parameter_file:
        parameters = KratosMultiphysics.Parameters(parameter_file.read())

    model = KratosMultiphysics.Model()
    simulation = StructuralMechanicsAnalysis(model,parameters)
    simulation.Run()
~~~

An example:

[test_wrapper](https://github.com/loumalouomega/KratosPythonWrapperApplication/tree/master/PythonWrapperApplication/test_examples/test_wrapper)

## Installation

Add the following lines to your configure.sh:

~~~sh
add_app "/this_folder/KratosPythonWrapperApplication/PythonWrapperApplication"  \
~~~ 
