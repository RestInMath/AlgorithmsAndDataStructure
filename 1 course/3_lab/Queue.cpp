#include "stdafx.h"
#include "Queue.h"

Queue::Queue() {

	rear = -1;

	front = 0;

}

Queue::~Queue()
{
	while (!isEmpty()) {
		dequeue();
	}
}

treeNode * Queue::top()
{
	return item[front];
}


void Queue::enqueue(treeNode* data) {

	item[++rear] = data;

}


treeNode* Queue::dequeue() {

	return item[front++];

}


int Queue::size() {

	return (rear - front + 1);

}

bool Queue::isEmpty() {

	if (front>rear) {

		return true;

	}
	else {

		return false;

	}

}

bool Queue::isFull() {

	if (this->size() >= MAX_SIZE) {

		return true;

	}
	else {

		return false;

	}

}