from __future__ import print_function, absolute_import, division #makes KratosMultiphysics backward compatible with python 2.6 and 2.7

# Import Kratos
import KratosMultiphysics as KM
from KratosPythonWrapperApplication import *

# Import OS
import os

def GetFilePath(fileName):
    return os.path.join(os.path.dirname(os.path.realpath(__file__)), fileName)

application = KratosPythonWrapperApplication()
application_name = "KratosPythonWrapperApplication"
application_folder = GetFilePath("PythonWrapperApplication")

KM._ImportApplicationAsModule(application, application_name, application_folder, __path__)
