#pragma once
#include <iostream>

template <class T>
class List;

template <typename key_type, typename value_type>
class RBTree;

class HuffmanNode;

template <class T>
class Node {

	friend class List<T>;
private:
	Node *next = nullptr, *prev = nullptr;

	template<class T>
	friend std::ostream &operator<<(std::ostream &stream, List<T> l);
	template<class T>
	friend std::ostream & operator<<(std::ostream & stream, List<T> *l);
public:
	T value;
	Node(T new_value) {
		value = new_value;
	}

	Node<T>* goNext();
};

template <class T>
class List {
private:
	Node<T> *root = nullptr, *last = nullptr;
	size_t list_size = 0;
	void check_index(size_t);

	//delete by node ptr (3 lab)
	void remove(Node<T>*);

	//Перегрузка операторов вывода
	template<class T>
	friend std::ostream &operator<<(std::ostream &stream, List<T> l);

	template<class T>
	friend std::ostream & operator<<(std::ostream & stream, List<T> *l);

	friend HuffmanNode* createHuffmanTree(RBTree <char, size_t>* map, List<HuffmanNode*>* leaves);
public:
	~List<T>();

	void push_back(T); // добавление в конец списка
	void push_front(T); // добавление в начало списка
	void pop_back(); // удаление последнего элемента
	void pop_front(); // удаление первого элемента
	void insert(size_t, T); // добавление элемента по индексу (вставка перед элементом, который был ранее доступен по этому индексу)
	T at(size_t); // получение элемента по индексу
	void remove(size_t); // удаление элемента по индексу
	size_t get_size(); // получение размера списка
	void clear(); // удаление всех элементов списка
	void set(size_t, T); // замена элемента по индексу на передаваемый элемент
	bool isEmpty(); // проверка на пустоту списка
	
	bool isEqual(List<T>*);
	Node<T>* getRoot();

	//for lab4
	bool contains(T val);
};

template<class T>
inline void List<T>::check_index(size_t index)
{
	if (index < 0 || index >= this->list_size) {
		throw (std::out_of_range("Incorrect index"));
	}
}

template<class T>
inline void List<T>::remove(Node<T>* node)
{

	if (node->prev != nullptr)
		node->prev->next = node->next;
	else
		this->root = node->next;

	if (node->next != nullptr)
		node->next->prev = node->prev;
	else
		this->last = node->prev;

	this->list_size--;
}

template<class T>
inline void List<T>::push_back(T new_val)
{
	if (root == nullptr) {
		Node<T> new_node(new_val);
		root = last = new Node<T>(new_val);
	}
	else {
		//insert new node after last node
		last->next = new Node<T>(new_val);
		last->next->prev = last;
		last = last->next;
	}

	list_size++;
}

template<class T>
inline void List<T>::push_front(T new_val)
{
	if (isEmpty()) {
		root = last = new Node<T>(new_val);
	}
	else {
		//insert new node before root node
		
		root->prev = new Node<T>(new_val);
		root->prev->next = root;
		root = root->prev;
	}

	list_size++;
}

template<class T>
inline void List<T>::pop_back()
{
	if (isEmpty()) {
		throw std::exception("Trying to delete node of empty list");
	}

	if (root == last) {
		delete root;
		root = nullptr;
		return;
	}

	last = last->prev;
	delete last->next;
	last->next = nullptr;

	list_size--;
}

template<class T>
inline void List<T>::pop_front()
{
	if (isEmpty()) {
		throw std::exception("Trying to delete node of empty list");
	}

	if (list_size == 1) {
		root = last = nullptr;
	}
	else {
		Node<T>* buf = root;
		root = root->next;
		delete buf;
		root->prev = nullptr;
	}

	list_size--;
}

template<class T>
inline void List<T>::insert(size_t pos, T new_value)
{
	if (pos == list_size) {
		push_back(new_value);
		return;
	}

	if (pos == 0) {
		push_front(new_value);
		return;
	}

	check_index(pos);

	//search of node before	sought-fore
	Node<T>* cur = root;
	size_t counter = 0;
	while (++counter < pos) {
		cur = cur->next;
	}

	//set value
	Node<T>* temp = cur->next;
	cur->next = new Node<T>(new_value);
	cur->next->next = temp;
	cur->next->prev = cur;
	cur->next->next->prev = cur->next;

	list_size++;
}

template<class T>
inline T List<T>::at(size_t pos)
{
	check_index(pos);

	//search of required node
	size_t counter = 0;
	Node<T>* cur = root;
	while (counter++ < pos) {
		cur = cur->next;
	}

	return cur->value;
}

template<class T>
inline void List<T>::remove(size_t pos)
{
	check_index(pos);

	if (pos == 0) {
		pop_front();
		return;
	}

	if (pos == list_size - 1) {
		pop_back();
		return;
	}

	//search of node before removable
	Node<T>* cur = root;
	size_t counter = 0;
	while (++counter < pos) {
		cur = cur->next;
	}

	//remove element
	Node<T>* temp = cur->next;
	cur->next = cur->next->next;
	cur->next->prev = cur;
	delete temp;

	list_size--;
}

template<class T>
inline size_t List<T>::get_size()
{
	return list_size;
}

template<class T>
inline void List<T>::clear()
{
	while (root != nullptr) {
		//delete last node while list is not empty
		pop_back();
	}
	//list_size = 0;
}

template<class T>
inline void List<T>::set(size_t pos, T new_value)
{
	check_index(pos);

	size_t counter = 0;
	Node<T>* cur = root;
	while (counter++ < pos) {
		cur = cur->next;
	}

	cur->value = new_value;
}

template<class T>
inline bool List<T>::isEmpty()
{
	return root == nullptr;
}

template<class T>
inline bool List<T>::isEqual(List<T>* other)
{
	Node<T>* cur = root, *other_cur = other->root;
	if (list_size != other->list_size)
		return false;

	while (cur != nullptr) {
		if (cur->value != other_cur->value) {
			return false;
		}
		cur = cur->next;
		other_cur = other_cur->next;
	}
	return true;
}

template<class T>
inline Node<T>* List<T>::getRoot()
{
	return root;
}

template<class T>
inline bool List<T>::contains(T val)
{
	Node<T>* cur = root;

	while (cur != nullptr) {
		if (cur->value == val)
			return true;
		cur = cur->next;
	}

	return false;
}

template<class T>
inline List<T>::~List()
{
	clear();
}

template<class T>
std::ostream & operator<<(std::ostream & stream, List<T> l)
{
	Node<T>* cur = l.root;
	size_t counter = 0;
	if (l.isEmpty()) {
		stream << "List is empty\n";
		return stream;
	}
	stream << "List content:\n";

	while (cur != nullptr) {
		stream << ++counter << " element: " << cur->value << '\n';
		cur = cur->next;
	 }
	return stream;
}

//check
template<class T>
std::ostream & operator<<(std::ostream & stream, List<T> *l)
{
	Node<T>* cur = l->root;
	size_t counter = 0;
	if (l->isEmpty()) {
		stream << "List is empty\n";
		return stream;
	}
	stream << "List content:\n";

	while (cur != nullptr) {
		stream << ++counter << " element: " << cur->value << '\n';
		cur = cur->next;
	}
	return stream;
}

template<class T>
inline Node<T>* Node<T>::goNext()
{
	return next;
}
