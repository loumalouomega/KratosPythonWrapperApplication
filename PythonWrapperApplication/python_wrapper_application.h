//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:           BSD License
//                          Kratos default license: kratos/license.txt
//
//  Main authors:    Vicente Mataix Ferrandiz
//


#if !defined(KRATOS_PYTHON_WRAPPER_APPLICATION_H_INCLUDED )
#define  KRATOS_PYTHON_WRAPPER_APPLICATION_H_INCLUDED


// System includes
#include <string>
#include <iostream>


// External includes


// Project includes
#include "includes/define.h"
#include "includes/kratos_application.h"
#include "includes/variables.h"


namespace Kratos {

///@name Kratos Globals
///@{

///@}
///@name Type Definitions
///@{

///@}
///@name  Enum's
///@{

///@}
///@name  Functions
///@{

///@}
///@name Kratos Classes
///@{

/// Short class definition.
/** Detail class definition.
*/
class KratosPythonWrapperApplication : public KratosApplication {
public:
     ///@name Type Definitions
     ///@{


     /// Pointer definition of KratosPythonWrapperApplication
     KRATOS_CLASS_POINTER_DEFINITION(KratosPythonWrapperApplication);

     ///@}
     ///@name Life Cycle
     ///@{

     /// Default constructor.
     KratosPythonWrapperApplication();

     /// Destructor.
     virtual ~KratosPythonWrapperApplication(){}


     ///@}
     ///@name Operators
     ///@{


     ///@}
     ///@name Operations
     ///@{

    void Register() override;

     ///@}
     ///@name Access
     ///@{


     ///@}
     ///@name Inquiry
     ///@{


     ///@}
     ///@name Input and output
     ///@{

     /// Turn back information as a string.
    std::string Info() const override
    {
          return "KratosPythonWrapperApplication";
     }

     /// Print information about this object.
    void PrintInfo(std::ostream& rOStream) const override
    {
          rOStream << Info();
          PrintData(rOStream);
     }

     ///// Print object's data.
    void PrintData(std::ostream& rOStream) const override
    {
        std::cout << "In KratosPythonWrapperApplication: " << KratosComponents<VariableData>::GetComponents().size() << " components" << std::endl;

        rOStream << "Variables:" << std::endl;
        KratosComponents<VariableData>().PrintData(rOStream);
        rOStream << std::endl;
        rOStream << "Elements:" << std::endl;
        KratosComponents<Element>().PrintData(rOStream);
        rOStream << std::endl;
        rOStream << "Conditions:" << std::endl;
        KratosComponents<Condition>().PrintData(rOStream);
    }


     ///@}
     ///@name Friends
     ///@{


     ///@}

protected:
     ///@name Protected static Member Variables
     ///@{


     ///@}
     ///@name Protected member Variables
     ///@{


     ///@}
     ///@name Protected Operators
     ///@{


     ///@}
     ///@name Protected Operations
     ///@{


     ///@}
     ///@name Protected  Access
     ///@{


     ///@}
     ///@name Protected Inquiry
     ///@{


     ///@}
     ///@name Protected LifeCycle
     ///@{


     ///@}

private:
     ///@name Static Member Variables
     ///@{

     // static const ApplicationCondition  msApplicationCondition;

     ///@}
     ///@name Member Variables
     ///@{

     // const Elem2D   mElem2D;
     // const Elem3D   mElem3D;

     ///@}
     ///@name Private Operators
     ///@{


     ///@}
     ///@name Private Operations
     ///@{


     ///@}
     ///@name Private  Access
     ///@{


     ///@}
     ///@name Private Inquiry
     ///@{


     ///@}
     ///@name Un accessible methods
     ///@{

     /// Assignment operator.
     KratosPythonWrapperApplication& operator=(KratosPythonWrapperApplication const& rOther);

     /// Copy constructor.
     KratosPythonWrapperApplication(KratosPythonWrapperApplication const& rOther);


     ///@}

}; // Class KratosPythonWrapperApplication

///@}


///@name Type Definitions
///@{


///@}
///@name Input and output
///@{

///@}


}  // namespace Kratos.

#endif // KRATOS_PYTHON_WRAPPER_APPLICATION_H_INCLUDED  defined
