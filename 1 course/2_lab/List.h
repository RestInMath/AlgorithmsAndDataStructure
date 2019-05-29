#pragma once
class List;

class Node {
private:
	Node *next = nullptr;
public:
	friend List;
	int num;
};

class List {
private:
	Node *root = nullptr, *last = nullptr, *cur = nullptr;
	size_t list_size = 0;
	void check_index(size_t);
public:
	~List();

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
	bool check_nums(int[], int len);
	bool isEqual(List* other);
};
