#include "stdafx.h"
#include <iostream>
#include "array_functions.h"

int cell_value(const size_t i, const size_t j, const size_t column_num, const size_t lines_num, int& last_var) {
	//check if current cell is central (x and y axis)
	bool center_j = (column_num % 2 ? j <= column_num / 2 : j < column_num / 2),
		center_i = (lines_num % 2 ? i <= lines_num / 2 : i < lines_num / 2);

	//upper half
	if (center_i) {
		if (j <= i && center_j)
			return ++last_var;

		if (j >= column_num - i && j > column_num / 2)
			return --last_var;

		return last_var;
	}
	//lower half
	else {
		if (j < lines_num - i && center_j)
			return ++last_var;

		if ((j > column_num - (lines_num - i)) && (j > column_num / 2))
			return --last_var;

		return last_var;
	}
}

void fill_array(int ** const frame_arr, const size_t lines_num, const size_t column_num, int first_val) {
	//this variable will change during the algorithm work
	int fill_value;

	for (size_t i = 0; i < lines_num; i++) {

		frame_arr[i] = new int[column_num];
		fill_value = first_val - 1;

		//value of each element forms in 'cell_value' function
		for (size_t j = 0; j < column_num; j++)
			frame_arr[i][j] = cell_value(i, j, column_num, lines_num, fill_value);
	}
}

void print_array(int ** const frame_arr, const size_t lines_num, const size_t column_num) {
	for (size_t i = 0; i < lines_num; i++) {
		for (size_t j = 0; j < column_num; j++) {
			//print array element, new line for new array row
			std::cout << frame_arr[i][j] << (j == column_num - 1 ? '\n' : '\t');
		}
	}
}

bool is_equal(int ** const array1, const size_t a1_lines, const size_t a1_columns, int ** const array2, const size_t a2_lines, const size_t a2_columns) {
	//check dimensions
	if (a1_lines != a2_lines || a1_columns != a2_columns)
		return false;

	for (size_t i = 0; i < a1_lines; i++) {
		for (size_t j = 0; j < a1_columns; j++) {
			if (array1[i][j] != array2[i][j]) return false;
		}
	}
	return true;
}

void delete_array(int ** const array, size_t lines_num) {
	for (size_t i = 0; i < lines_num; i++) {
		delete array[i];
	}
	delete[] array;
}
