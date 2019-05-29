#pragma once
#include "stdafx.h"
#include "RBTree_.h"
#include "Stack.h"
#include "Queue.h"
template <typename key_type, typename value_type>
class RBTree;

class route;

template <typename key_type, typename value_type> class DFT_TreeIterator {
	friend class RBTree<typename key_type, typename value_type>;
	friend HuffmanNode* createHuffmanTree(RBTree <char, size_t>*, List<HuffmanNode*>* leaves);
public:
	DFT_TreeIterator(size_t count, TreeNode<key_type, value_type> * head);
	size_t node_amount = 0;
	bool has_next();
	key_type next();
	value_type next_val();
	TreeNode<key_type, value_type>* getCurrent();
private:
	~DFT_TreeIterator();
	TreeNode<key_type, value_type>* current;
	void dft();
	struct Stack<key_type, value_type> callStack;
};

template <typename key_type, typename value_type> class DFT_sort_TreeIterator {
	friend class RBTree<typename key_type, typename value_type>;
	friend void Dijsktra(RBTree<std::string, List<route>*> *, std::string, List<std::string>*);
	friend std::string find_min_new_route(RBTree<std::string, List<route>*>* map, RBTree<std::string, int>* city_routes, List<std::string>* visited);
private:
	struct Queue<key_type, value_type> callQueue;
	void dft_preorder(TreeNode<key_type, value_type> *);
	size_t node_amount;
	TreeNode<key_type, value_type> * getCurrent();
public:
	DFT_sort_TreeIterator(size_t, TreeNode<key_type, value_type> *);
	~DFT_sort_TreeIterator();

	bool has_next();
	key_type next();
};

template<typename key_type, typename value_type>
inline DFT_TreeIterator<key_type, value_type>::DFT_TreeIterator(size_t count, TreeNode<key_type, value_type> * head)
{
	node_amount = count;
	if (!head->isNIL()) {
		current = head;
		callStack.push(head);
	}
}

template<typename key_type, typename value_type>
inline bool DFT_TreeIterator<key_type, value_type>::has_next()
{
	return !callStack.isEmpty();
}

template<typename key_type, typename value_type>
inline key_type DFT_TreeIterator<key_type, value_type>::next()
{
	TreeNode<key_type, value_type>* temp = callStack.show_top();
	dft();
	return temp->key;
}

template<typename key_type, typename value_type>
inline value_type DFT_TreeIterator<key_type, value_type>::next_val()
{
	TreeNode<key_type, value_type>* temp = callStack.show_top();
	dft();
	return temp->value;
}

template<typename key_type, typename value_type>
inline DFT_TreeIterator<key_type, value_type>::~DFT_TreeIterator()
{
	callStack.~Stack();
	treeNode<key_type, value_type>* current = nullptr;
	size_t node_amount = 0;
}

template<typename key_type, typename value_type>
inline TreeNode<key_type, value_type>* DFT_TreeIterator<key_type, value_type>::getCurrent()
{
	return callStack.show_top();
}

template<typename key_type, typename value_type>
inline void DFT_TreeIterator<key_type, value_type>::dft()
{
	if (!has_next()) {
		throw std::out_of_range("Iteration has over");
	}

	//get element from call stack
	current = callStack.pop();

	//add left and right nodes to call stack
	if (!current->right->isNIL()) {
		callStack.push(current->right);
	}
	if (!current->left->isNIL()) {
		callStack.push(current->left);
	}
}

template<typename key_type, typename value_type>
inline void DFT_sort_TreeIterator<key_type, value_type>::dft_preorder(TreeNode<key_type, value_type> * root)
{
	if (!root->isNIL())
	{
		dft_preorder(root->left);
		callQueue.enqueue(root);
		dft_preorder(root->right);
	}
}

template<typename key_type, typename value_type>
inline TreeNode<key_type, value_type>* DFT_sort_TreeIterator<key_type, value_type>::getCurrent()
{
	return callQueue.top();
}

template<typename key_type, typename value_type>
inline DFT_sort_TreeIterator<key_type, value_type>::DFT_sort_TreeIterator(size_t count, TreeNode<key_type, value_type> * root)
{
	dft_preorder(root);
	node_amount = count;
}

template<typename key_type, typename value_type>
inline DFT_sort_TreeIterator<key_type, value_type>::~DFT_sort_TreeIterator()
{
	callQueue.~Queue();
	TreeNode<key_type, value_type>* current = nullptr;
	size_t node_amount = 0;
}

template<typename key_type, typename value_type>
inline bool DFT_sort_TreeIterator<key_type, value_type>::has_next()
{
	return !callQueue.isEmpty();
}

template<typename key_type, typename value_type>
inline key_type DFT_sort_TreeIterator<key_type, value_type>::next()
{
	if (!has_next())
		throw std::out_of_range("Iteration has over");
	return callQueue.dequeue()->key;
}
