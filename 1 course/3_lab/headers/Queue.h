#pragma once
#define MAX_SIZE 1000
class treeNode;

class Queue {

private:

	treeNode* item[MAX_SIZE];

	int rear = -1;

	int front;

public:

	Queue();
	~Queue();

	treeNode * top();

	void enqueue(treeNode*);

	treeNode* dequeue();

	int size();

	bool isEmpty();

	bool isFull();

};