#include "stdafx.h"
#include "Tree.h"
#include "Stack.h"
#include <iostream>

using namespace std;

int main()
{
	BinarySearchTree lst;

	lst.insert(5);
	lst.insert(8);
	lst.insert(3);
	lst.insert(6);
	lst.insert(1);
	lst.insert(9);
	lst.insert(10);
	lst.insert(9);

	lst.print();

	lst.remove(3);
	lst.remove(8);
	cout << "AFTER REMOVE\n";
	lst.print();

	TreeIterator* dft_sort = lst.create_sort_iterator();
	while (dft_sort->has_next()) {
		cout << dft_sort->next() << ' ';
	}
	cout << '\n';

	return 0;
}

