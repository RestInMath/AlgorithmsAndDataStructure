#pragma once
#include "stdafx.h"
#include <vector>
#include "Stack.h"
#include "Queue.h"

class treeNode;
class BinarySearchTree;

//abstract class
class TreeIterator {
	friend BinarySearchTree;
public:
	size_t node_amount = 0;

	TreeIterator();

	//virtual functions
	virtual  bool has_next() = 0;
	virtual int next() = 0;
private:
	virtual treeNode* getCurrent() = 0;
	treeNode *current;
};

//legacy iterator, using breadth-first traverse
class BFT_TreeIterator : public TreeIterator {
private:
	Queue queue;
	treeNode* current;
	size_t node_amount;
	void bft();
public:
	BFT_TreeIterator(size_t count, treeNode* head);
	~BFT_TreeIterator();

	int next() override;
	bool has_next() override;
	treeNode* getCurrent() override;
};

//legacy iterator, using depth-first traverse
class DFT_TreeIterator : public TreeIterator {
	friend BinarySearchTree;
private:
	treeNode* getCurrent() override;
	struct Stack callStack;
	void dft();
	treeNode *current;
	size_t node_amount;
public:
	DFT_TreeIterator(size_t, treeNode *);
	~DFT_TreeIterator();

	bool has_next() override;
	int next() override;

};

//legacy iterator, using preorder depth-first traverse
class DFT_sort_TreeIterator : public TreeIterator{
private:
	struct Queue callQueue;
	void dft_preorder(treeNode *);
	size_t node_amount;
	treeNode * getCurrent();
public:
	DFT_sort_TreeIterator(size_t, treeNode *);
	~DFT_sort_TreeIterator();

	bool has_next() override;
	int next() override;
};

class BinarySearchTree{
private:
	treeNode *head = nullptr;
	size_t node_amount = 0;
	void print(treeNode*, int);
	void insert(treeNode *);
public:

	BinarySearchTree();
	~BinarySearchTree();
	
	void insert(int);
	bool contains(int);
	void remove(int);
	//wrapper for private print
	void print();
	
	//create iterators
	TreeIterator * create_bft_iterator();
	TreeIterator * create_dft_iterator();
	TreeIterator * create_sort_iterator();
	
	//getters
	size_t getNodeAmount();
};

class treeNode {
private:
	int data;
	friend DFT_TreeIterator;
	friend BFT_TreeIterator;
	friend TreeIterator;
	friend BinarySearchTree;
	friend DFT_sort_TreeIterator;

	treeNode *left = nullptr, *right = nullptr;
	
	~treeNode();

};

bool is_equal(int * const, const size_t, int * const, const size_t);