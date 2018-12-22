#pragma once
void fill_array(int ** const frame_arr, const size_t lines_num, const size_t column_num, int first_val);

void print_array(int ** const frame_arr, const size_t lines_num, const size_t column_num);

bool is_equal(int ** const array1, const size_t a1_lines, const size_t a1_columns, int ** const array2, const size_t a2_lines, const size_t a2_columns);

void delete_array(int ** array, size_t lines_num);
