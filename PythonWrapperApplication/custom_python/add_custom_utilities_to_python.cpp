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
#include <pybind11/pybind11.h>

// Project includes
#include "includes/define.h"
#include "processes/process.h"
#include "custom_python/add_custom_utilities_to_python.h"
#include "custom_utilities/python_object_cpp_wrapper_utility.h"

namespace Kratos {
namespace Python {

void  AddCustomUtilitiesToPython(pybind11::module& m)
{
    using namespace pybind11;

    // Python Object To C++ Wrapper Utility
    class_<PythonObjectCppWrapperUtility, typename PythonObjectCppWrapperUtility::Pointer>(m, "PythonObjectCppWrapperUtility")
    .def(init< >())
    .def(init<  pybind11::list&>())
    .def(init<  pybind11::object&>())
    .def("AddObject",&PythonObjectCppWrapperUtility::AddObject)
    .def("AddObjects",&PythonObjectCppWrapperUtility::AddObjects)
    .def("Execute",&PythonObjectCppWrapperUtility::Execute)
    .def("RunStructuralAnalysisStage",&PythonObjectCppWrapperUtility::RunStructuralAnalysisStage)
    ;
}

} // namespace Python.
} // Namespace Kratos
