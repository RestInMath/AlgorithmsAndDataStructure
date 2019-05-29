#include "stdafx.h"
#include "Stack.h"
#include <iostream>

Stack::Stack()
{
	top = -1; 
}

bool Stack::push(treeNode * x)
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

treeNode * Stack::pop()
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

bool Stack::isEmpty()
{
	return (top < 0);
}

treeNode * Stack::show_top()
{
	return a[top];
}
