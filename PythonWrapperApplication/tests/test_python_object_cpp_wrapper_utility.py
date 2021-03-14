import KratosMultiphysics
import KratosMultiphysics.PythonWrapperApplication as PythonWrapperApplication

import KratosMultiphysics.KratosUnittest as KratosUnittest

class DummyClass():
    def DummyMethod(self):
        self.this_assert = True

class TestPythonObjectCppWrapperUtility(KratosUnittest.TestCase):
    def setUp(self):
        pass

    def test_process_factory(self):
        dummy_class = DummyClass()
        python_wrapper = PythonWrapperApplication.PythonObjectCppWrapperUtility(dummy_class)
        #dummy_class.DummyMethod()
        python_wrapper.Execute("DummyMethod")
        self.assertTrue(dummy_class.this_assert)

    def test_processes_list_factory(self):
        dummy_class1 = DummyClass()
        dummy_class2 = DummyClass()
        dummy_list = [dummy_class1, dummy_class2]
        python_wrapper = PythonWrapperApplication.PythonObjectCppWrapperUtility(dummy_list)
        #dummy_class.DummyMethod()
        python_wrapper.Execute("DummyMethod")
        self.assertTrue(dummy_class1.this_assert)
        self.assertTrue(dummy_class2.this_assert)

if __name__ == '__main__':
    KratosUnittest.main()
