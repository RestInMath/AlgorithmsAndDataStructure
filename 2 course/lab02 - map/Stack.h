#pragma once
#define MAX 1000
#include <iostream>

template <typename key_type, typename value_type> class TreeNode;

template <typename key_type, typename value_type>
class Stack
{
	int top = -1;
public:
	TreeNode<key_type, value_type> * a[MAX];		   //Maximum size of Stack 

	Stack();
	bool push(TreeNode<key_type, value_type>* x);
	TreeNode<key_type, value_type> *pop();
	bool isEmpty();
	TreeNode<key_type, value_type>* show_top();
};


template<typename key_type, typename value_type>
Stack<key_type, value_type>::Stack()
{
	top = -1;
}

template<typename key_type, typename value_type>
bool Stack<key_type, value_type>::push(TreeNode<key_type, value_type>* x)
{
	if (top >= (MAX - 1))
	{
		throw std::out_of_range("Stack Overflow");
		return false;
	}
	else
	{
		a[++top] = x;
		return true;
	}
}

template<typename key_type, typename value_type>
TreeNode<key_type, value_type>* Stack<key_type, value_type>::pop()
{
	if (top < 0)
	{
		throw std::out_of_range("Stack Underflow");
		return 0;
	}
	else
	{
		return a[top--];
	}
}

template<typename key_type, typename value_type>
bool Stack<key_type, value_type>::isEmpty()
{
	return (top < 0);
}

template<typename key_type, typename value_type>
TreeNode<key_type, value_type>* Stack<key_type, value_type>::show_top()
{
	return a[top];
}
