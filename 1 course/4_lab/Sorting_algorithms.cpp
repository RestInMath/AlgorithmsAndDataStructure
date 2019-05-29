#include "stdafx.h"
#include "Sorting_algorithms.h"
#include <vector>

void check_index(int index) {
	if (index < 0)
		throw std::out_of_range("Incorrect index");
}

int PartialbinarySearch(int* arr, size_t left, size_t right, int Search_for)
{
	if(right >= left){

		int middle = left + (right - left) / 2;

		if (arr[middle] == Search_for)
			return middle;


		if (arr[middle] > Search_for)
			return PartialbinarySearch(arr, left, middle - 1, Search_for);
		
		else
			return PartialbinarySearch(arr, middle + 1, right, Search_for);
	}
	return -1;
}

int binarySearch(int *arr, size_t len, int search_for)
{	

	if (search_for < arr[0] || search_for > arr[len-1]) {
		throw std::exception("Incorrect usage of binarySearch function");
	}
	check_index(len);

	return PartialbinarySearch(arr, 0, len-1, search_for);
}

int partition(int *arr, size_t low, size_t high)
{
	int pivot = arr[high];
	int i = low - 1; 

	for (size_t j = low; j <= high-1; j++) {
		if (arr[j] <= pivot) {
			i++;
			std::swap(arr[i], arr[j]);
			//i++;
		}
	}
	std::swap(arr[i+1], arr[high]);
	return i+1;
}

void QuickSortPrivate(int * arr, size_t begin, size_t end) {
	if (begin < end) {
		int pi = partition(arr, begin, end);

		QuickSortPrivate(arr, begin, pi - 1);
		QuickSortPrivate(arr, pi + 1, end);
	}
}

void QuickSort(int *arr, size_t len)
{
	check_index(len);
	QuickSortPrivate(arr, 0, len-1);
	
}

void insertionSort(int *arr, int len)
{
	check_index(len);
	//O(n) - O(n^2)
	int key, j;
	for (int i = 1; i < len; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void treeSort(int *arr, size_t len) {
	check_index(len);

	BinarySearchTree btr;
	for (size_t i = 0; i < len; i++)
		btr.insert(arr[i]);

	TreeIterator* it = btr.create_sort_iterator();

	for (size_t i = 0; i < len; i++)
		arr[i] = it->next();

	delete it;
}

bool is_sorted(int *arr, size_t len) {
	check_index(len);
	for (size_t i = 0; i < len-1; i++) {
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}

void bogoSort(int *arr, size_t len)
{
	check_index(len);
	//O(n*n!)
	while (!is_sorted(arr, len)) {
		for (size_t i = 0; i < len; ++i) {
			size_t j = rand() % len;
			std::swap(arr[i], arr[j]);
		}
	}
}

void print_arr(int *arr, size_t len)
{
	check_index(len);
	for (size_t i = 0; i < len; i++)
		std::cout << arr[i] << ' ';

	std::cout << '\n';
}

void countingSort(char *arr, size_t len) {
	check_index(len);

	char *arr_out = new char[len];

	int count_array[256] = { 0 };
	size_t i;

	for (i = 0; i < len; i++)
		count_array[arr[i]]++;
	

	size_t arr_out_index = 0;
	for (int i = 0; i < 256; i++) {
		for (size_t j = 0; j < count_array[i]; j++) {
			arr[arr_out_index++] = i;
		}
	}
}