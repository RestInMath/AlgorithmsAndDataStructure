#pragma once
#define MAX 1000

class treeNode;

class Stack
{
	int top = -1;
public:
	treeNode * a[MAX];		   //Maximum size of Stack 

	Stack();
	bool push(treeNode* x);
	treeNode * pop();
	bool isEmpty();
	treeNode * show_top();
};