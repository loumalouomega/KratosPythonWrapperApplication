//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:		 BSD License
//					 Kratos default license: kratos/license.txt
//
//  Main authors:    Vicente Mataix Ferrandiz
//

// System includes

// External includes

// Project includes
#include "python_wrapper_application.h"
#include "python_wrapper_application_variables.h"

namespace Kratos {

KratosPythonWrapperApplication::KratosPythonWrapperApplication():
    KratosApplication("PythonWrapperApplication")
    {}

void KratosPythonWrapperApplication::Register() {
    // Calling base class register to register Kratos components
    KratosApplication::Register();
    KRATIS_INFO("") << "Initializing KratosPythonWrapperApplication... " << std::endl;
}
}  // namespace Kratos.
