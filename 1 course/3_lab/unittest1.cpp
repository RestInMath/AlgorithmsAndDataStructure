#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AaDS3/Tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TreesTest
{		
	TEST_CLASS(DFT_sort_iterator_tests)
	{
	public:
		BinarySearchTree *btr;
		TreeIterator * dft_sort;

		TEST_METHOD_INITIALIZE(init) {
			btr = new BinarySearchTree;
		}

		TEST_METHOD_CLEANUP(cleanUp) {
			btr->~BinarySearchTree();
			delete dft_sort;
		}
	
		TEST_METHOD(DFS_sort_insert_3_level) {
			btr->insert(5);
			btr->insert(8);
			btr->insert(3);
			btr->insert(6);
			btr->insert(1);
			btr->insert(9);
			btr->insert(10);

			dft_sort = btr->create_sort_iterator();
			size_t arr_len = btr->getNodeAmount();
			int *check_tree_arr = new int[arr_len];
			int check[] = { 1,3,5,6,8,9,10 };

			int i = 0;
			while (dft_sort->has_next()) {
				check_tree_arr[i++] = dft_sort->next();
			}

			Assert::IsTrue(is_equal(check, 7, check_tree_arr, 7));
		}

		TEST_METHOD(DFS_sort_insert_1_element) {

			btr->insert(8);
			dft_sort = btr->create_sort_iterator();

			Assert::AreEqual(8, dft_sort->next());
		}
		
		TEST_METHOD(has_next_dft_sort) {
			btr->insert(1);
			dft_sort = btr->create_sort_iterator();

			Assert::IsTrue(dft_sort->has_next());
		}

		TEST_METHOD(next_in_empty_dft_sort) {
			dft_sort = btr->create_sort_iterator();
			try {
				dft_sort->next();
			}
			catch (std::exception e) {
				Assert::AreEqual(e.what(), "Iteration has over");
			}
		}

	};


	TEST_CLASS(DFT_iterator_tests) {
		BinarySearchTree *btr;
		TreeIterator *dft_it;

		TEST_METHOD_INITIALIZE(dft_init) {
			 btr = new BinarySearchTree;
		}

		TEST_METHOD_CLEANUP(dft_cleanUp) {
			btr->~BinarySearchTree();
			delete dft_it;
		}

		TEST_METHOD(DFS_insert_3_level) {
			btr->insert(5);
			btr->insert(8);
			btr->insert(3);
			btr->insert(6);
			btr->insert(1);
			btr->insert(9);
			btr->insert(10);

			dft_it = btr->create_dft_iterator();
			size_t arr_len = btr->getNodeAmount();
			int *check_tree_arr = new int[arr_len];
			int check[] = { 5,3,1,8,6,9,10 };

			int i = 0;
			while (dft_it->has_next()) {
				check_tree_arr[i++] = dft_it->next();
			}

			Assert::IsTrue(is_equal(check, 7, check_tree_arr, 7));
		}

		TEST_METHOD(DFS_insert_1_element) {

			btr->insert(8);
			dft_it = btr->create_dft_iterator();

			Assert::AreEqual(8, dft_it->next());
		}

		TEST_METHOD(has_next_dft) {
			btr->insert(1);
			TreeIterator * dft_it = btr->create_dft_iterator();

			Assert::IsTrue(dft_it->has_next());
		}

		TEST_METHOD(next_in_empty_dft) {
			dft_it = btr->create_dft_iterator();
			try {
				dft_it->next();
			}
			catch (std::exception e) {
				Assert::AreEqual(e.what(), "Iteration has over");
			}
		}

		TEST_METHOD(has_next_from_empty_tree) {
			dft_it = btr->create_dft_iterator();
			Assert::IsFalse(dft_it->has_next());
		}
	};


	TEST_CLASS(BFT_iterator_tests) {

		BinarySearchTree *btr;
		TreeIterator *bft_it;

		TEST_METHOD_INITIALIZE(dfs_test_init) {
			btr = new BinarySearchTree;
		}

		TEST_METHOD_CLEANUP(dfs_test_cleanUp) {
			btr->~BinarySearchTree();
			delete bft_it;
		}

		TEST_METHOD(BFS_insert_3_level) {
			btr->insert(5);
			btr->insert(8);
			btr->insert(3);
			btr->insert(6);
			btr->insert(1);
			btr->insert(9);
			btr->insert(10);

			bft_it = btr->create_bft_iterator();
			size_t arr_len = btr->getNodeAmount();
			int *check_tree_arr = new int[arr_len];
			int check[] = { 5,3,8,1,6,9,10 };

			int i = 0;
			while (bft_it->has_next()) {
				check_tree_arr[i++] = bft_it->next();
			}

			Assert::IsTrue(is_equal(check, 7, check_tree_arr, 7));
		}
	
		TEST_METHOD(BFS_insert_1_element) {

			btr->insert(8);
			bft_it = btr->create_bft_iterator();

			Assert::AreEqual(8, bft_it->next());
		}
	
		TEST_METHOD(has_next_bft) {
			btr->insert(1);
			bft_it = btr->create_bft_iterator();

			Assert::IsTrue(bft_it->has_next());
		}

		TEST_METHOD(next_in_empty_dft) {
			bft_it = btr->create_dft_iterator();
			try {
				bft_it->next();
			}
			catch (std::exception e) {
				Assert::AreEqual(e.what(), "Iteration has over");
			}
		}

		TEST_METHOD(next_in_empty_bft) {
			bft_it = btr->create_bft_iterator();
			try {
				bft_it->next();
			}
			catch (std::exception e) {
				Assert::AreEqual(e.what(), "Iteration has over");
			}
		}
	};


	TEST_CLASS(TreeTests) {
		BinarySearchTree *btr;

		TEST_METHOD_INITIALIZE(treeTestInit) {
			btr = new BinarySearchTree;
		}

		TEST_METHOD_CLEANUP(treeTestCleanUp) {
			btr->~BinarySearchTree();
		}

		TEST_METHOD(contains_1_element_after_insert) {
			btr->insert(4);
			Assert::IsTrue(btr->contains(4));
		}

		TEST_METHOD(conatins_from_Empty_tree)
		{
			Assert::IsFalse(btr->contains(20));
		}

		TEST_METHOD(conatins_not_after_remove) {
			btr->insert(5);
			btr->remove(5);
			Assert::IsFalse(btr->contains(5));
		}

		TEST_METHOD(insert_contains_3_level) {
			btr->insert(5);
			btr->insert(8);
			btr->insert(3);
			btr->insert(6);
			btr->insert(1);
			btr->insert(9);
			btr->insert(10);

			size_t arr_len = btr->getNodeAmount();
			bool all_number_in_tree = true;
			int check[] = { 5,3,1,8,6,9,10 };

			for (size_t i = 0; i < arr_len; i++) {
				if (!btr->contains(check[i]))
					all_number_in_tree = false;
			}

			Assert::IsTrue(all_number_in_tree);
		}

		TEST_METHOD(node_amount) {
			btr->insert(5);
			btr->insert(8);
			btr->insert(3);
			btr->insert(6);
			btr->insert(1);
			btr->insert(9);
			btr->insert(10);

			Assert::IsTrue(btr->getNodeAmount() == 7);
		}

		TEST_METHOD(remove_check_by_DFS) {

			btr->insert(5);
			btr->insert(8);
			btr->insert(3);
			btr->insert(6);
			btr->insert(1);
			btr->insert(9);
			btr->insert(10);

			btr->remove(3);
			btr->remove(9);

			TreeIterator * dft_it = btr->create_dft_iterator();

			int check_arr[] = { 5,1,8,6,10 };
			size_t arr_len = btr->getNodeAmount();
			int *seq_from_tree = new int[arr_len];

			for (size_t i = 0; i < arr_len; i++) {
				seq_from_tree[i] = dft_it->next();
			}
			Assert::IsTrue(is_equal(seq_from_tree, arr_len, check_arr, arr_len));
			delete dft_it;
		}

		TEST_METHOD(remove_check_after_node_amount) {
			btr->insert(5);
			btr->insert(8);
			btr->insert(3);
			btr->insert(6);
			btr->insert(1);
			btr->insert(9);
			btr->insert(10);
			btr->insert(19);

			btr->remove(19);

			Assert::IsTrue(btr->getNodeAmount() == 7);
		}

		TEST_METHOD(remove_wrong_key) {
			try { 
				btr->remove(20); 
			}
			catch (std::exception e) {
				Assert::AreEqual(e.what(), "No such element in tree");
			}
		}
	};
}