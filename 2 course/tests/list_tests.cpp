#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AaDS_4sem/Template list.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace ListTests
{		

	TEST_CLASS(Init_tests)
	{
	public:

		TEST_METHOD(list_init_int)
		{
			try {
				List<int> nl;
				Assert::IsTrue(true);
			}
			catch (std::exception e) {
				Assert::IsTrue(false);
			}
		}

		TEST_METHOD(list_init_char)
		{
			try {
				List<char> nl;
				Assert::IsTrue(true);
			}
			catch (std::exception e) {
				Assert::IsTrue(false);
			}
		}

		TEST_METHOD(list_init_double)
		{
			try {
				List<double> nl;
				Assert::IsTrue(true);
			}
			catch (std::exception e) {
				Assert::IsTrue(false);
			}
		}
	
		TEST_METHOD(list_init_myclass)
		{
			TestClass myClass;
			try {
				List<TestClass> nl;
				Assert::IsTrue(true);
			}
			catch (std::exception e) {
				Assert::IsTrue(false);
			}
		}
	};

	TEST_CLASS(add_elemets_test)
	{
	public:

		TEST_METHOD(push_back_int)
		{
			List<int> nl;
			nl.push_back(101);
			Assert::IsTrue(nl.at(0) == 101 && nl.get_size() == 1);
		}

		TEST_METHOD(push_back_double)
		{
			List<double> nl;
			nl.push_back(10.1);
			Assert::IsTrue(nl.at(0) == 10.1 && nl.get_size() == 1);
		}
			
		TEST_METHOD(push_back_char)
		{
			List<char> nl;
			nl.push_back('o');
			Assert::IsTrue(nl.at(0) == 'o' && nl.get_size() == 1);
		}

		TEST_METHOD(push_back_string)
		{
			List<std::string> nl;
			nl.push_back("one hundred one");
			Assert::IsTrue(nl.at(0) == "one hundred one" && nl.get_size() == 1);
		}

		/*TEST_METHOD(push_back_myClass)
		{
			TestClass myExemp;
			List<TestClass> nl;
			nl.push_back(myExemp);
			Assert::IsTrue(nl.at(0) == myExemp);
		}*/
	};

	TEST_CLASS(List_int_tests)
	{
	public:

		List<int> *lst;

		TEST_METHOD_INITIALIZE(setUp) {
			lst = new List<int>();
		}

		TEST_METHOD_CLEANUP(cleanUp) {
			delete lst;
		}

		TEST_METHOD(push_back_3)
		{
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);

			Assert::IsTrue(lst->at(0)==1 && lst->at(1)==2 && lst->at(2)==3 && lst->get_size() == 3);
		}

		TEST_METHOD(push_front_4) {
			lst->push_front(5);
			lst->push_front(4);
			lst->push_front(3);
			lst->push_front(2);

			Assert::IsTrue(lst->at(0) == 2 && lst->at(1) == 3 && lst->at(2) == 4 && lst->at(3) == 5 && lst->get_size()==4);
		}

		TEST_METHOD(push_back_and_front_4) {
			lst->push_back(3);
			lst->push_front(2);
			lst->push_front(1);
			lst->push_back(4);

			Assert::IsTrue(lst->at(0) == 1 && lst->at(1) == 2 && lst->at(2) == 3 && lst->at(3) == 4 && lst->get_size() == 4);
		}

		TEST_METHOD(push_back_and_insert_5) {
			lst->push_back(2);
			lst->push_back(3);
			lst->push_back(5);
			lst->insert(0, 1);
			lst->insert(3, 4);

			int check_arr[] = { 1,2,3,4,5 };
			Assert::IsTrue(lst->at(0) == 1 && lst->at(1) == 2 && lst->at(2) == 3 && lst->at(3) == 4 && lst->at(4) == 5 && lst->get_size() == 5);
		}

		TEST_METHOD(insert_4_true) {
			lst->insert(0, 2);
			lst->insert(0, 1);
			lst->insert(2, 4);
			lst->insert(2, 3);

			int nums_to_compare[] = { 1, 2, 3, 4 };

			Assert::IsTrue(lst->at(0) == 1 && lst->at(1) == 2 && lst->at(2) == 3 && lst->at(3) == 4 && lst->get_size() == 4);
		}

		TEST_METHOD(is_empty_after_clear) {
			lst->push_back(2);
			lst->push_back(3);
			lst->push_back(5);
			lst->clear();

			Assert::IsTrue(lst->isEmpty());
		}

		TEST_METHOD(at_3) {
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);

			Assert::AreEqual(2, lst->at(1));
		}

		TEST_METHOD(at_incorrect_index) {
			lst->push_back(1);
			lst->push_back(2);
			try {
				lst->at(2);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Incorrect index", e.what());
			}
		}

		TEST_METHOD(remove_middle_list) {
			lst->push_back(2);
			lst->push_back(3);
			lst->push_back(5);
			lst->insert(0, 1);
			lst->insert(3, 4);
			lst->remove(3);

			int check_arr[] = { 1,2,3,5 };
			Assert::IsTrue(lst->at(0) == 1 && lst->at(1) == 2 && lst->at(2) == 3 && lst->at(3) == 5 && lst->get_size() == 4);
		}

		TEST_METHOD(remove_last_node) {
			lst->push_back(2);
			lst->push_back(3);
			lst->push_back(5);
			lst->insert(0, 1);
			lst->insert(3, 4);
			lst->remove(4);

			int check_arr[] = { 1,2,3,4 };
			Assert::IsTrue(lst->at(0) == 1 && lst->at(1) == 2 && lst->at(2) == 3 && lst->at(3) == 4 && lst->get_size() == 4);
		}

		TEST_METHOD(remove_first_node) {
			lst->push_back(2);
			lst->push_back(3);
			lst->push_back(5);
			lst->insert(0, 1);
			lst->insert(3, 4);
			lst->remove(0);

			int check_arr[] = { 2,3,4,5 };
			Assert::IsTrue(lst->at(0) == 2 && lst->at(1) == 3 && lst->at(2) == 4 && lst->at(3) == 5 && lst->get_size() == 4);
		}

		TEST_METHOD(get_size) {
			lst->push_back(2);
			lst->push_back(3);
			lst->push_back(5);
			lst->insert(1, 0);
			lst->insert(4, 3);
			lst->push_back(6);
			lst->pop_back();
			lst->pop_front();

			Assert::AreEqual(4, (int)lst->get_size());
		}

		TEST_METHOD(set) {
			lst->push_back(2);
			lst->push_back(3);
			lst->push_back(5);
			lst->insert(0, 1);
			lst->insert(3, 4);
			lst->set(0, 8);
			lst->set(3, 9);

			int check_arr[] = { 8,2,3,9,5 };
			Assert::IsTrue(lst->at(0)==8 && lst->at(1)==2 && lst->at(2) == 3 && lst->at(3) == 9 && lst->at(4)==5 && lst->get_size() == 5);
		}

		TEST_METHOD(incorrect_index_set) {
			try {
				lst->set(-1, 2);
			}
			catch (std::exception e) {
				Assert::AreEqual(e.what(), "Incorrect index");
			}
		}

		TEST_METHOD(incorrect_index_insert) {
			try {
				lst->insert(1, -1);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Incorrect index", e.what());
			}
		}

		TEST_METHOD(incorrect_index)
		{
			try {
				lst->at(-1);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Incorrect index", e.what());
			}
		}

		TEST_METHOD(remove_is_empty) {
			lst->push_back(1);
			lst->push_back(2);
			lst->remove(0);
			lst->remove(0);

			Assert::IsTrue(lst->isEmpty());
		}

		TEST_METHOD(pop_back_is_empty) {
			lst->push_front(2);
			lst->push_front(1);

			lst->pop_back();
			lst->pop_back();
			Assert::IsTrue(lst->isEmpty());
		}

		TEST_METHOD(pop_back_1_node) {
			lst->push_front(1);

			lst->pop_back();
			Assert::IsTrue(lst->isEmpty());
		}

		TEST_METHOD(pop_back_in_empty_list) {

			try {
				lst->pop_back();
			}
			catch (std::exception e) {
				Assert::AreEqual("Trying to delete node of empty list", e.what());
			}
		}

		TEST_METHOD(pop_front_in_empty_list) {

			try {
				lst->pop_front();
			}
			catch (std::exception e) {
				Assert::AreEqual("Trying to delete node of empty list", e.what());
			}
		}

		TEST_METHOD(pop_front_1_node) {
			lst->push_back(1);

			lst->pop_front();
			Assert::IsTrue(lst->isEmpty());
		}

	};

	TEST_CLASS(List_char_tests)
	{
	public:

		List<char> *lst;

		TEST_METHOD_INITIALIZE(setUp) {
			lst = new List<char>();
		}

		TEST_METHOD_CLEANUP(cleanUp) {
			delete lst;
		}

		TEST_METHOD(push_back_3)
		{
			lst->push_back('a');
			lst->push_back('b');
			lst->push_back('c');

			Assert::IsTrue(lst->at(0) == 'a' && lst->at(1) == 'b' && lst->at(2) == 'c' && lst->get_size() == 3);
		}

		TEST_METHOD(push_front_4) {
			lst->push_front('c');
			lst->push_front('d');
			lst->push_front('e');
			lst->push_front('f');

			Assert::IsTrue(lst->at(0) == 'f' && lst->at(1) == 'e' && lst->at(2) == 'd' && lst->at(3) == 'c' && lst->get_size() == 4);
		}

		TEST_METHOD(push_back_and_insert_5) {
			lst->push_back('b');
			lst->push_back('c');
			lst->push_back('e');
			lst->insert(0, 'a');
			lst->insert(3, 'd');

			int check_arr[] = { 1,2,3,4,5 };
			Assert::IsTrue(lst->at(0) == 'a' && lst->at(1) == 'b' && lst->at(2) == 'c' && lst->at(3) == 'd' && lst->at(4) == 'e' && lst->get_size() == 5);
		}

		TEST_METHOD(insert_4_true) {
			lst->insert(0, 'b');
			lst->insert(0, 'a');
			lst->insert(2, 'd');
			lst->insert(2, 'c');

			Assert::IsTrue(lst->at(0) == 'a' && lst->at(1) == 'b' && lst->at(2) == 'c' && lst->at(3) == 'd' && lst->get_size() == 4);
		}

		TEST_METHOD(is_empty_after_clear) {
			lst->push_back('a');
			lst->push_back('f');
			lst->push_back('g');
			lst->clear();

			Assert::IsTrue(lst->isEmpty());
		}

		TEST_METHOD(at_3) {
			lst->push_back('a');
			lst->push_back('b');
			lst->push_back('c');

			Assert::AreEqual('b', lst->at(1));
		}

		TEST_METHOD(at_incorrect_index) {
			lst->push_back('a');
			lst->push_back('b');
			try {
				lst->at('b');
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Incorrect index", e.what());
			}
		}

		TEST_METHOD(remove_middle_list) {
			lst->push_back('b');
			lst->push_back('c');
			lst->push_back('e');
			lst->insert(0, 'a');
			lst->insert(3, 'd');
			lst->remove(3);

			int check_arr[] = { 'a','b','c','e' };
			Assert::IsTrue(lst->at(0) == 'a' && lst->at(1) == 'b' && lst->at(2) == 'c' && lst->at(3) == 'e' && lst->get_size() == 4);
		}

		/*TEST_METHOD(remove_last_node) {
		lst->push_back(2);
		lst->push_back(3);
		lst->push_back(5);
		lst->insert(0, 1);
		lst->insert(3, 4);
		lst->remove(4);

		int check_arr[] = { 1,2,3,4 };
		Assert::IsTrue(lst->at(0) == 1 && lst->at(1) == 2 && lst->at(2) == 3 && lst->at(3) == 4 && lst->get_size() == 4);
		}

		TEST_METHOD(remove_first_node) {
		lst->push_back(2);
		lst->push_back(3);
		lst->push_back(5);
		lst->insert(0, 1);
		lst->insert(3, 4);
		lst->remove(0);

		int check_arr[] = { 2,3,4,5 };
		Assert::IsTrue(lst->at(0) == 2 && lst->at(1) == 3 && lst->at(2) == 4 && lst->at(3) == 5 && lst->get_size() == 4);
		}*/

		TEST_METHOD(get_size) {
			lst->push_back('g');
			lst->push_back('f');
			lst->push_back('d');
			lst->insert(1, 't');
			lst->insert(4, 'h');
			lst->push_back(6);
			lst->pop_back();
			lst->pop_front();

			Assert::AreEqual(4, (int)lst->get_size());
		}

		TEST_METHOD(set) {
			lst->push_back(2);
			lst->push_back(3);
			lst->push_back(5);
			lst->insert(0, 1);
			lst->insert(3, 4);
			lst->set(0, 8);
			lst->set(3, 9);

			int check_arr[] = { 8,2,3,9,5 };
			Assert::IsTrue(lst->at(0) == 8 && lst->at(1) == 2 && lst->at(2) == 3 && lst->at(3) == 9 && lst->at(4) == 5 && lst->get_size() == 5);
		}

		/*TEST_METHOD(incorrect_index_set) {
		try {
		lst->set(-1, 2);
		}
		catch (std::exception e) {
		Assert::AreEqual(e.what(), "Incorrect index");
		}
		}

		TEST_METHOD(incorrect_index_insert) {
		try {
		lst->insert(1, -1);
		}
		catch (std::out_of_range e) {
		Assert::AreEqual("Incorrect index", e.what());
		}
		}

		TEST_METHOD(incorrect_index)
		{
		try {
		lst->at(-1);
		}
		catch (std::out_of_range e) {
		Assert::AreEqual("Incorrect index", e.what());
		}
		}*/

		TEST_METHOD(remove_is_empty) {
			lst->push_back('r');
			lst->push_back('e');
			lst->remove(0);
			lst->remove(0);

			Assert::IsTrue(lst->isEmpty());
		}

		TEST_METHOD(pop_back_is_empty) {
			lst->push_front('g');
			lst->push_front('d');

			lst->pop_back();
			lst->pop_back();
			Assert::IsTrue(lst->isEmpty());
		}

		TEST_METHOD(pop_back_1_node) {
			lst->push_front('1');

			lst->pop_back();
			Assert::IsTrue(lst->isEmpty());
		}

		TEST_METHOD(pop_back_in_empty_list) {

			try {
				lst->pop_back();
			}
			catch (std::exception e) {
				Assert::AreEqual("Trying to delete node of empty list", e.what());
			}
		}

		TEST_METHOD(pop_front_in_empty_list) {

			try {
				lst->pop_front();
			}
			catch (std::exception e) {
				Assert::AreEqual("Trying to delete node of empty list", e.what());
			}
		}

		TEST_METHOD(pop_front_1_node) {
			lst->push_back('q');

			lst->pop_front();
			Assert::IsTrue(lst->isEmpty());
		}

	};

	TEST_CLASS(List_TestClass_tests)
	{
	public:
		class TestClass {
		public:
			double first_field = 5.20;
			char second_field = 'r';
			std::string third_field = "Some String";

			TestClass(double first_val, char sec_val, std::string third_val) {
				first_field = first_val;
				second_field = sec_val;
				third_field = third_val;
			}

			friend bool operator==(const TestClass fmc, const TestClass smc) {
				return (fmc.first_field == smc.first_field && fmc.second_field == smc.second_field && fmc.third_field == smc.third_field);
			}
		};

		List<TestClass*> *lst;
		TestClass *fExemp, *sExemp;

		TEST_METHOD_INITIALIZE(setUp) {
			lst = new List<TestClass*>();
			fExemp = new TestClass(1.4, 't', "first"), sExemp = new TestClass(2.5, 'm', "second");
		}

		TEST_METHOD_CLEANUP(cleanUp) {
			delete lst;
			delete fExemp, sExemp;
		}

		TEST_METHOD(push_back_2_TestCLass)
		{
			lst->push_back(fExemp);
			lst->push_back(sExemp);

			Assert::IsTrue(lst->at(0) == fExemp && lst->at(1) == sExemp && lst->get_size() == 2);
		}

		TEST_METHOD(push_front_2_TestClass) {
			lst->push_front(sExemp);
			lst->push_front(fExemp);

			Assert::IsTrue(lst->at(0) == fExemp && lst->at(1) == sExemp && lst->get_size() == 2);
		}

		TEST_METHOD(insert_2_true_TestClass) {
			lst->insert(0, sExemp);
			lst->insert(0, fExemp);

			Assert::IsTrue(lst->at(0) == fExemp && lst->at(1) == sExemp && lst->get_size() == 2);
		}

		TEST_METHOD(is_empty_after_clear) {
			lst->push_back(fExemp);
			lst->push_back(sExemp);
			lst->clear();

			Assert::IsTrue(lst->isEmpty());
		}

		TEST_METHOD(at_Testlass) {
			lst->push_back(fExemp);
			lst->push_back(sExemp);

			Assert::IsTrue(sExemp == lst->at(1));
		}

		TEST_METHOD(at_incorrect_index_TestClass) {
			lst->push_back(fExemp);
			lst->push_back(sExemp);
			try {
				lst->at(3);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Incorrect index", e.what());
			}
		}
	};
}