#include "stdafx.h"
#include "List.h"
#include <iostream>

void List::push_back(int n) {
	if (isEmpty()) {
		root = last = new Node;
		last->num = n;
	}
	else {
		//insert new node after last node
		last->next = new Node;
		last->next->num = n;
		last = last->next;
	}

	list_size++;
}

void List::push_front(int n) {
	if (isEmpty()) {
		root = last = new Node;
		root->num = n;
	}
	else {
		//insert new node before root node
		Node *temp = root;
		root = new Node;
		root->num = n;
		root->next = temp;
	}

	list_size++;
}

void List::pop_back() {
	if (isEmpty()) {
		throw std::exception("Trying to delete node of empty list");
	}

	if (root == last) {
		delete root;
		root = nullptr;
		return;
	}

	cur = root;
	while (cur->next != last) {
		cur = cur->next;
	}

	last = cur;
	delete last->next;
	last->next = nullptr;

	list_size--;
}

void List::pop_front() {
	if (isEmpty()) {
		throw std::exception("Trying to delete node of empty list");
	}

	Node* buf = root;
	root = root->next;
	delete buf;

	list_size--;
}

void List::insert(int n, size_t p) {
	if (p == list_size) {
		push_back(n);
		return;
	}

	if (p == 0) {
		push_front(n);
		return;
	}

	check_index(p);

	//search of node before	sought-fore
	cur = root;
	size_t counter = 0;
	while (++counter < p) {
		cur = cur->next;
	}

	//set value
	Node* temp = cur->next;
	cur->next = new Node;
	cur->next->num = n;
	cur->next->next = temp;

	list_size++;
}

int List::at(size_t p) {
	check_index(p);

	//search of required node
	size_t counter = 0;
	cur = root;
	while (counter++ < p) {
		cur = cur->next;
	}

	return cur->num;
}

void List::remove(size_t p) {
	check_index(p);

	if (p == 0) {
		pop_front();
		return;
	}

	//search of node before removable
	cur = root;
	size_t counter = 0;
	while (++counter < p) {
		cur = cur->next;
	}

	//remove element
	Node *buf = cur->next;
	cur->next = cur->next->next;
	delete buf;

	list_size--;
}

size_t List::get_size() {
	return list_size;
}

void List::print_to_console() {
	cur = root;
	while (cur != nullptr) {
		std::cout << cur->num << ' ';
		cur = cur->next;
	}
	std::cout << std::endl;
}

void List::clear() {
	while (root != nullptr) {
		//delete first node, go to next
		pop_front();
	}
	list_size = 0;
}

void List::set(size_t p, int n) {
	check_index(p);

	size_t counter = 0;
	cur = root;
	while (counter++ < p) {
		cur = cur->next;
	}

	cur->num = n;
}

bool List::isEmpty() {
	return root == nullptr;
}

//find first entrance of outer list l in this list
size_t List::find_first_entrance(List l) {
	cur = root;
	size_t counter_l = 0, counter = 0, target_point;
	l.cur = l.root;

	while (cur != nullptr) {
		//List contain current node of outer list
		if (cur->num == l.cur->num) {

			//List contain first node of outer list, potential point
			if (counter_l == 0) {
				target_point = counter;
			}

			//List contains whole outer list
			if (++counter_l == l.get_size()) {
				return target_point;
			}

			//move to next node of outer list
			l.cur = l.cur->next;
		}
		else {
			//current node of outer list is not in this list
			counter_l = 0;
			l.cur = l.root;
		}
		cur = cur->next;
		counter++;
	}

	throw std::out_of_range("List doesn`t contain outer list");
}

//check if index is out of range
void List::check_index(size_t index) {
	if (index < 0 || index >= this->get_size()) {
		throw (std::out_of_range("Incorrect index"));
	}
}

//check num sequence in list
bool List::check_nums(int nums[], int len) {
	size_t counter = 0;
	cur = root;

	check_index(len-1);

	while (cur != nullptr) {
		if (cur->num != nums[counter++])
			return false;
		cur = cur->next;
	}

	return true;
}

bool List::isEqual(List * other)
{
	if (list_size != other->list_size)
		return false;

	while (cur != nullptr) {
		if (cur->num != other->cur->num) {
			return false;
		}
		cur = cur->next;
	}
	return true;
}
