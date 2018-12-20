#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AaSD2/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ListTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		List *lst;

		TEST_METHOD_INITIALIZE(setUp) {
			lst = new List();
		}

		TEST_METHOD_CLEANUP(cleanUp) {
			delete lst;
		}

		TEST_METHOD(push_back_3)
		{
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);

			int list_nums[] = { 1,2,3 };

			Assert::IsTrue(lst->check_nums(list_nums, 3));
		}

		TEST_METHOD(push_front_4) {
			lst->push_front(5);
			lst->push_front(4);
			lst->push_front(3);
			lst->push_front(2);

			int check_arr[] = { 2,3,4,5 };

			Assert::IsTrue(lst->check_nums(check_arr, 4));
		}

		TEST_METHOD(push_back_and_front_4) {
			lst->push_back(3);
			lst->push_front(2);
			lst->push_front(1);
			lst->push_back(4);

			int check_arr[] = { 1,2,3,4 };
			Assert::IsTrue(lst->check_nums(check_arr, 4));
		}

		TEST_METHOD(push_back_and_insert_5) {
			lst->push_back(2);
			lst->push_back(3);
			lst->push_back(5);
			lst->insert(1, 0);
			lst->insert(4, 3);

			int check_arr[] = { 1,2,3,4,5 };
			Assert::IsTrue(lst->check_nums(check_arr, 5));
		}

		TEST_METHOD(insert_true) {
			lst->insert(2, 0);
			lst->insert(1, 0);
			lst->insert(4, 2);
			lst->insert(3, 2);

			int nums_to_compare[] = { 1, 2, 3, 4 };

			Assert::IsTrue(lst->check_nums(nums_to_compare, 4));
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
			lst->insert(1, 0);
			lst->insert(4, 3);
			lst->remove(3);

			int check_arr[] = { 1,2,3,5 };
			Assert::IsTrue(lst->check_nums(check_arr, 4));
		}

		TEST_METHOD(remove_last_node) {
			lst->push_back(2);
			lst->push_back(3);
			lst->push_back(5);
			lst->insert(1, 0);
			lst->insert(4, 3);
			lst->remove(4);

			int check_arr[] = { 1,2,3,4 };
			Assert::IsTrue(lst->check_nums(check_arr, 4));
		}

		TEST_METHOD(remove_first_node) {
			lst->push_back(2);
			lst->push_back(3);
			lst->push_back(5);
			lst->insert(1, 0);
			lst->insert(4, 3);
			lst->remove(0);

			int check_arr[] = { 2,3,4,5 };
			Assert::IsTrue(lst->check_nums(check_arr, 4));
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

			Assert::AreEqual(4, (int) lst->get_size());
		}

		TEST_METHOD(set) {
			lst->push_back(2);
			lst->push_back(3);
			lst->push_back(5);
			lst->insert(1, 0);
			lst->insert(4, 3);
			lst->set(0, 8);
			lst->set(3, 9);

			int check_arr[] = { 8,2,3,9,5 };
			Assert::IsTrue(lst->check_nums(check_arr, 5));
		}

		TEST_METHOD(incorrect_index_set) {
			try {
				lst->set(-1, 2);
			}
			catch (std::exception e) {
				Assert::AreEqual(e.what(), "Incorrect index");
			}
		}

		TEST_METHOD(find_first_entrance_1node_list) {
			lst->push_back(2);
			lst->push_back(3);
			lst->push_back(5);
			lst->insert(1, 0);
			lst->insert(4, 3);

			List slst;

			slst.push_back(3);

			Assert::AreEqual(2, (int)lst->find_first_entrance(slst));
		}

		TEST_METHOD(find_first_entrance_false) {
			lst->push_back(2);
			lst->push_back(3);
			lst->push_back(5);
			lst->insert(1, 0);
			lst->insert(4, 3);

			List slst;
			slst.push_back(5);
			slst.push_front(4);
			slst.push_back(6);

			Assert::AreEqual(-1, (int) lst->find_first_entrance(slst));
		}

		TEST_METHOD(find_first_entrance_3node_list) {
			lst->push_back(2);
			lst->push_back(3);
			lst->push_back(5);
			lst->insert(1, 0);
			lst->insert(4, 3);

			List slst;
			slst.push_back(5);
			slst.push_front(4);
			slst.insert(3, 0);

			Assert::AreEqual(2, (int)lst->find_first_entrance(slst));
		}

		TEST_METHOD(find_first_entrance_2_entrance) {
			lst->push_back(3);
			lst->push_back(5);
			lst->insert(1, 0);
			lst->insert(4, 2);
			lst->push_back(6);
			lst->push_back(3);
			lst->push_back(4);
			lst->push_back(5);
			lst->push_back(2);
			//134563452 - sequence in list

			List slst;
			slst.push_back(5);
			slst.push_front(4);
			slst.insert(3, 0);
			//345

			Assert::AreEqual(1, (int)lst->find_first_entrance(slst));
		}

		TEST_METHOD(find_first_entrance_outer_list_bigger) {
			lst->push_back(2);
			lst->push_back(3);
			lst->push_back(4);
			lst->insert(1, 0);

			List slst;
			slst.push_back(1);
			slst.push_back(2);
			slst.push_back(3);
			slst.push_back(4);
			slst.push_back(5);

			Assert::AreEqual(-1, (int)lst->find_first_entrance(slst));
		}

		TEST_METHOD(find_first_entrance_self) {
			lst->push_back(3);
			lst->push_back(5);
			lst->insert(1, 0);
			lst->insert(4, 2);
			lst->push_back(6);
			lst->push_back(3);
			lst->push_back(4);
			lst->push_back(5);
			lst->push_back(2);
			//134563452 - sequence in list

			Assert::AreEqual(0, (int)lst->find_first_entrance(*lst));
		}

		TEST_METHOD(check_num_out_of_range) {
			lst->push_back(5);
			lst->push_back(7);
			lst->push_back(9);

			int nums_to_compare[] = { 5,7,9,8 };
			try {
				lst->check_nums(nums_to_compare, 4);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Incorrect index", e.what());
			}
		}

		TEST_METHOD(check_num_false) {
			lst->push_back(5);
			lst->push_back(7);
			lst->push_back(9);

			int nums_to_compare[] = { 5,7,8 };
			
			Assert::IsFalse(lst->check_nums(nums_to_compare, 3));
			
		}

		TEST_METHOD(check_num_true) {
			lst->push_back(5);
			lst->push_back(7);
			lst->push_back(9);

			int nums_to_compare[] = { 5,7,9 };

			Assert::IsTrue(lst->check_nums(nums_to_compare, 3));

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
			catch(std::out_of_range e){
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
}