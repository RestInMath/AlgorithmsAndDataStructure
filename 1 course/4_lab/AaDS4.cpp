#include "stdafx.h"
#include "Sorting_algorithms.h"
#include <iostream>

int main()
{
	int arr[] = { 15,23,4,7,12,18 };

	char ch_arr[] = { 'k', 'o', 'k', 'b', 'a', 'i' };

	countingSort(ch_arr, 6);

	QuickSort(arr, 6);

	std::cout << binarySearch(arr, 6, 15) << '\n';
	
	print_arr(arr, 6);

    return 0;
}

