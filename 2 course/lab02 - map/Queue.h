#pragma once
#define MAX_SIZE 1000
template <typename key_type, typename value_type> class TreeNode;

template <typename key_type, typename value_type>
class Queue {

private:

	TreeNode<key_type, value_type>* item[MAX_SIZE];

	int rear = -1;

	int front;

public:

	Queue();
	~Queue();

	TreeNode<key_type, value_type> * top();

	void enqueue(TreeNode<key_type, value_type> *);

	TreeNode<key_type, value_type>* dequeue();

	bool isEmpty();

	bool isFull();

};

template<typename key_type, typename value_type>
Queue<key_type, value_type>::Queue()
{
	rear = -1;

	front = 0;
}

template<typename key_type, typename value_type>
inline Queue<key_type, value_type>::~Queue()
{
	while (!isEmpty()) {
		dequeue();
	}
}

template<typename key_type, typename value_type>
inline TreeNode<key_type, value_type>* Queue<key_type, value_type>::top()
{
	return item[front];
}

template<typename key_type, typename value_type>
void Queue<key_type, value_type>::enqueue(TreeNode<key_type, value_type>* data)
{
	item[++rear] = data;
}

template<typename key_type, typename value_type>
TreeNode<key_type, value_type>* Queue<key_type, value_type>::dequeue()
{
	return item[front++];
}

template<typename key_type, typename value_type>
bool Queue<key_type, value_type>::isEmpty()
{
	if (front > rear) {

		return true;

	}
	else {

		return false;

	}
}

template<typename key_type, typename value_type>
bool Queue<key_type, value_type>::isFull()
{
	if (rear - front + 1 >= MAX_SIZE) {

		return true;

	}
	else {

		return false;

	}
}