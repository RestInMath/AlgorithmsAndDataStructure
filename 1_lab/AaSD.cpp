#include "stdafx.h"
#include <iostream>
#include "array_functions.h"

void input(size_t &lines_num, size_t &column_num, int &first_val) throw() {
	try { std::cin >> lines_num >> column_num >> first_val; }
	catch (std::exception e) {
		throw std::exception("Input integer nums");
	}

	if (lines_num < 0 || column_num < 0) {
		throw std::out_of_range("negative index");
	}
}

int main()
{
	size_t lines_num, column_num;
	int first_val;

	input(lines_num, column_num, first_val);

	int **frame_arr = new int*[lines_num];
	
	fill_array(frame_arr, lines_num, column_num, first_val);

	print_array(frame_arr, lines_num, column_num);

	delete_array(frame_arr, lines_num);

    return 0;
}

