#pragma once
class Node {
public:
	int num;
	Node *next = nullptr;
};

class List {
private:
	Node *root = nullptr, *last = nullptr, *cur = nullptr;
	size_t list_size = 0;

public:
	void push_back(int);
	void push_front(int);
	void pop_back();
	void pop_front();
	void insert(int, size_t);
	int at(size_t);
	void remove(size_t);
	size_t get_size();
	void print_to_console();
	void clear();
	void set(size_t, int);
	bool isEmpty();
	size_t find_first_entrance(List);
	void check_index(size_t);
	bool check_nums(int[], int len);
	bool isEqual(List* other);
};

void check_index(size_t);