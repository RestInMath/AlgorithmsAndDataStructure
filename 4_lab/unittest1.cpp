#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AaDS4/Sorting_algorithms.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortTest
{		
	TEST_CLASS(sorting_test)
	{
	public:

		TEST_METHOD(quicksort_right)
		{
			int array_in[] = { 15,23,4,7,12,18 };
			int check_arr[] = { 4,7,12,15,18,23 };

			QuickSort(array_in, 6);

			Assert::IsTrue(is_equal(array_in, 6, check_arr, 6));
		}

		TEST_METHOD(quicksort_incorrect_usage) {
			int check_arr[] = { 4,7,12,15,18,23 };

			try {
				QuickSort(check_arr, -1);
			}
			catch (std::exception e) {
				Assert::AreEqual(e.what(), "Incorrect index");
			}
		}

		TEST_METHOD(quicksort_1_elemnt) {
			int array_in[] = { 1 };

			QuickSort(array_in, 1);

			Assert::IsTrue(1 == array_in[0]);
		}

		TEST_METHOD(binSort) {
			int array_in[] = { 15,23,4,7,12,18 };
			int check_arr[] = { 4,7,12,15,18,23 };

			treeSort(array_in, 6);

			Assert::IsTrue(is_equal(array_in, 6, check_arr, 6));
		}

		TEST_METHOD(insertionSort_test) {
			int array_in[] = { 15,23,4,7,12,18 };
			int check_arr[] = { 4,7,12,15,18,23 };

			insertionSort(array_in, 6);

			Assert::IsTrue(is_equal(array_in, 6, check_arr, 6));
		}

		TEST_METHOD(insertionSort_incorrect) {
			int array_in[] = { 15,23,4,7,12,18 };

			try {
				insertionSort(array_in, -1);
			}
			catch (std::exception e) {
				Assert::AreEqual(e.what(), "Incorrect index");
			}
		}

		TEST_METHOD(binSearch_incorrect_usage) {
			int array_in[] = { 15,23,4,7,12,18 };

			try {
				binarySearch(array_in, 6, 4);
			}
			catch (std::exception e) {
				Assert::AreEqual(e.what(), "Incorrect usage of binarySearch function");
			}
		}

		TEST_METHOD(binSearch_correct) {
			int array_in[] = { 4,7,12,15,18,23 };

			Assert::AreEqual(3, binarySearch(array_in, 6, 15));
		}

		TEST_METHOD(binSearch_false) {
			int array_in[] = { 15,23,4,7,12,18 };
			try {
				Assert::AreEqual(-1, binarySearch(array_in, -6, 11));
			}
			catch (std::exception e) {
				Assert::IsTrue(true);
			}
		}
	
		TEST_METHOD(counting_sort_right) {
			char choka[] = { 'k', 'o', 'k', 'b', 'a', 'i' };
			char check_arr[] = { 'a', 'b', 'i', 'k', 'k', 'o' };

			countingSort(choka, 6);
			for (size_t i = 0; i < 6; i++)
				Assert::IsTrue(choka[i] == check_arr[i]);
		}
	
		TEST_METHOD(counting_sort_incorrect) {
			char choka[] = { 'k', 'o', 'k', 'b', 'a', 'i' };

			
			try {
			countingSort(choka, -1);
			}
			catch (std::exception e) {
				Assert::AreEqual(e.what(), "Incorrect index");
			}
		}
	
		TEST_METHOD(binSort_incorrect) {
			int array_in[] = { 15,23,4,7,12,18 };

			try {
				treeSort(array_in, -1);
			}
			catch (std::exception e) {
				Assert::AreEqual(e.what(), "Incorrect index");
			}
		}
	
		TEST_METHOD(bogoSort_right) {
			int array_in[] = { 3,4,1,2 };
			bogoSort(array_in, 4);

			for (size_t i = 0, k = 1; i < 4; i++, k++)
				Assert::IsTrue(array_in[i] == k);
		}
	
		TEST_METHOD(bogoSort_incorrect_index) {
			int array_in[] = { 15,23,4,7,12,18 };

			try {
				bogoSort(array_in, -1);
			}
			catch (std::exception e) {
				Assert::AreEqual(e.what(), "Incorrect index");
			}
		}
};
}