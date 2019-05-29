#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AaSD/array_functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{

	TEST_CLASS(UnitTest1)
	{
	public:

		int **res_arr, **check_arr;

		TEST_METHOD(true_1x1_1)
		{
			const size_t rows = 1, columns = 1;
			res_arr = new int*[rows], check_arr = new int*[rows];
			res_arr[0] = new int[columns];

			res_arr[0][0] = 1;
			fill_array(check_arr, rows, columns, 1);
			Assert::IsTrue(is_equal(check_arr, rows, columns, res_arr, columns, 1));
		}

		TEST_METHOD(true_2x3_3) {
			const size_t rows = 2, columns = 3;
			res_arr = new int*[rows], check_arr = new int*[rows];

			int arr1[columns] = { 3,3,3 };
			int arr2[columns] = { 3,3,3 };
			res_arr[0] = arr1;
			res_arr[1] = arr2;

			fill_array(check_arr, rows, columns, 3);
			Assert::IsTrue(is_equal(check_arr, rows, columns, res_arr, rows, columns));
		}

		TEST_METHOD(true_3x2_4) {
			const size_t rows = 3, columns = 2;
			res_arr = new int*[rows], check_arr = new int*[rows];

			int arr1[columns] = { 4,4 };
			int arr2[columns] = { 4,4 };
			int arr3[columns] = { 4,4 };
			res_arr[0] = arr1;
			res_arr[1] = arr2;
			res_arr[2] = arr3;

			fill_array(check_arr, rows, columns, 4);
			Assert::IsTrue(is_equal(check_arr, rows, columns, res_arr, rows, columns));
		}

		TEST_METHOD(true_5x7_6) {
			const size_t rows = 5, columns = 7;
			res_arr = new int*[rows], check_arr = new int*[rows];

			int arr1[columns] = { 6,6,6,6,6,6,6 };
			int arr2[columns] = { 6,7,7,7,7,7,6 };
			int arr3[columns] = { 6,7,8,8,8,7,6 };
			int arr4[columns] = { 6,7,7,7,7,7,6 };
			int arr5[columns] = { 6,6,6,6,6,6,6 };

			res_arr[0] = arr1;
			res_arr[1] = arr2;
			res_arr[2] = arr3;
			res_arr[3] = arr4;
			res_arr[4] = arr5;

			fill_array(check_arr, rows, columns, 6);
			Assert::IsTrue(is_equal(check_arr, rows, columns, res_arr, rows, columns));
		}

		TEST_METHOD(true_7x5_6) {
			const size_t rows = 7, columns = 5;
			res_arr = new int*[rows], check_arr = new int*[rows];

			int arr1[columns] = { 6,6,6,6,6 };
			int arr2[columns] = { 6,7,7,7,6 };
			int arr3[columns] = { 6,7,8,7,6 };
			int arr4[columns] = { 6,7,8,7,6 };
			int arr5[columns] = { 6,7,8,7,6 };
			int arr6[columns] = { 6,7,7,7,6 };
			int arr7[columns] = { 6,6,6,6,6 };

			res_arr[0] = arr1;
			res_arr[1] = arr2;
			res_arr[2] = arr3;
			res_arr[3] = arr4;
			res_arr[4] = arr5;
			res_arr[5] = arr6;
			res_arr[6] = arr7;


			fill_array(check_arr, rows, columns, 6);
			Assert::IsTrue(is_equal(check_arr, rows, columns, res_arr, rows, columns));
		}

		TEST_METHOD(true_4x8_5) {
			const size_t rows = 4, columns = 8;
			res_arr = new int*[rows], check_arr = new int*[rows];

			int arr1[columns] = { 5,5,5,5,5,5,5,5 };
			int arr2[columns] = { 5,6,6,6,6,6,6,5 };
			int arr3[columns] = { 5,6,6,6,6,6,6,5 };
			int arr4[columns] = { 5,5,5,5,5,5,5,5 };

			res_arr[0] = arr1;
			res_arr[1] = arr2;
			res_arr[2] = arr3;
			res_arr[3] = arr4;

			fill_array(check_arr, rows, columns, 5);
			Assert::IsTrue(is_equal(check_arr, rows, columns, res_arr, rows, columns));
		}
	
		TEST_METHOD(true_8x6_5) {
			const size_t rows = 8, columns = 6;
			res_arr = new int*[rows], check_arr = new int*[rows];

			int arr1[columns] = { 5,5,5,5,5,5 };
			int arr2[columns] = { 5,6,6,6,6,5 };
			int arr3[columns] = { 5,6,7,7,6,5 };
			int arr4[columns] = { 5,6,7,7,6,5 };
			int arr5[columns] = { 5,6,7,7,6,5 };
			int arr6[columns] = { 5,6,7,7,6,5 };
			int arr7[columns] = { 5,6,6,6,6,5 };
			int arr8[columns] = { 5,5,5,5,5,5 };

			res_arr[0] = arr1;
			res_arr[1] = arr2;
			res_arr[2] = arr3;
			res_arr[3] = arr4;
			res_arr[4] = arr5;
			res_arr[5] = arr6;
			res_arr[6] = arr7;
			res_arr[7] = arr8;

			fill_array(check_arr, rows, columns, 5);
			Assert::IsTrue(is_equal(check_arr, rows, columns, res_arr, rows, columns));
		}

		TEST_METHOD(true_5x5_2) {
			const size_t rows = 5, columns = 5;
			res_arr = new int*[rows], check_arr = new int*[rows];

			int arr1[columns] = { 2,2,2,2,2 };
			int arr2[columns] = { 2,3,3,3,2 };
			int arr3[columns] = { 2,3,4,3,2 };
			int arr4[columns] = { 2,3,3,3,2 };
			int arr5[columns] = { 2,2,2,2,2 };

			res_arr[0] = arr1;
			res_arr[1] = arr2;
			res_arr[2] = arr3;
			res_arr[3] = arr4;
			res_arr[4] = arr5;

			fill_array(check_arr, rows, columns, 2);
			Assert::IsTrue(is_equal(check_arr, rows, columns, res_arr, rows, columns));
		}
	
		TEST_METHOD(false_3x4_1) {
			const size_t rows = 3, columns = 4;
			res_arr = new int*[rows], check_arr = new int*[rows];

			int arr1[columns] = { 1,1,1,1 };
			int arr2[columns] = { 1,2,2,1 };
			int arr3[columns] = { 1,2,2,2 };
			int arr4[columns] = { 1,1,1,1 };

			res_arr[0] = arr1;
			res_arr[1] = arr2;
			res_arr[2] = arr3;
			res_arr[3] = arr4;

			fill_array(check_arr, rows, columns, 2);
			Assert::IsFalse(is_equal(check_arr, rows, columns, res_arr, rows, columns));
		}

		TEST_METHOD(true_eq_arrays_3) {
			res_arr = new int*[3], check_arr = new int*[3];

			int arr1[] = { 1,2,3 };
			int arr2[] = { 4,5,6 };
			int arr3[] = { 7,8,9 };

			res_arr[0] = arr1, check_arr[0] = arr1;
			res_arr[1] = arr2, check_arr[1] = arr2;
			res_arr[2] = arr3, check_arr[2] = arr3;

			Assert::IsTrue(is_equal(res_arr, 3, 3, check_arr, 3, 3));
		}

		TEST_METHOD(true_1x3_1) {
			const size_t rows = 1, columns = 3;
			res_arr = new int*[rows], check_arr = new int*[rows];

			int arr1[] = { 1,1,1 };
			res_arr[0] = arr1;

			fill_array(check_arr, rows, columns, 1);
			Assert::IsTrue(is_equal(res_arr, 1, 3, check_arr, 1, 3));
		}

		TEST_METHOD(true_3x1_2) {
			const size_t rows = 3, columns = 1;
			res_arr = new int*[rows], check_arr = new int*[rows];

			int arr1[] = { 2 };
			int arr2[] = { 2 };
			int arr3[] = { 2 };
			res_arr[0] = arr1;
			res_arr[1] = arr2;
			res_arr[2] = arr3;

			fill_array(check_arr, rows, columns, 2);
			Assert::IsTrue(is_equal(res_arr, 3, 1, check_arr, 3, 1));
		}

		TEST_METHOD(eq_arrays_dif_dimensions) {
			const int len1 = 2, len2 = 3;
			res_arr = new int*[len1], check_arr = new int*[len2];

			int arr1[len1] = { 1,1 };
			int arr2[len1] = { 1,1 };

			int sec_arr1[len2] = { 1,1,1 };
			int sec_arr2[len2] = { 1,1,1 };
			int sec_arr3[len2] = { 1,1,1 };

			res_arr[0] = arr1;
			res_arr[1] = arr2;

			check_arr[0] = sec_arr1;
			check_arr[1] = sec_arr2;
			check_arr[2] = sec_arr3;
			
			Assert::IsFalse(is_equal(res_arr, len1, len1, check_arr, len2, len2));

			delete[] res_arr, check_arr;
		}
	
	};
}