#include "stdafx.h"
#include "Tree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree()
{
	head = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	if (head != nullptr)
	{
		TreeIterator * iterator = create_sort_iterator();
		treeNode * last;
		while (iterator->has_next())
		{
			last = iterator->getCurrent();
			iterator->next();
			delete last;
		}
		delete iterator;
	}
}

//create new node with int value and add to tree
void BinarySearchTree::insert(int insert_value)
{ 
	if (head == nullptr) {
		head = new treeNode;
		head->data = insert_value;
		node_amount++;
		return;
	}

	treeNode * current = head;
	while (true) {
		if (insert_value < current->data) {
			if (current->left == nullptr) {
				current->left = new treeNode;
				current->left->data = insert_value;
				node_amount++;
				return;
			}
			else
				current = current->left;
		}
		else if (insert_value >= current->data) {
			if (current->right == nullptr) {
				current->right = new treeNode;
				current->right->data = insert_value;
				node_amount++;
				return;
			}
			else
				current = current->right;
		}
	}
}

//add node to tree
void BinarySearchTree::insert(treeNode * insert_node)
{
	bool just_left = true;

	if (head == nullptr) {
		head = new treeNode;
		head->data = insert_node->data;
		return;
	}

	treeNode * current = head;
	while (current->data != insert_node->data) {
		if (insert_node->data < current->data) {
			if (current->left == nullptr) {
				current->left = insert_node;
			}
			else
				current = current->left;
		}
		else if (insert_node->data >= current->data) {
			if (current->right == nullptr) {
				current->right = insert_node;
			}
			else
				current = current->right;
		}
	}
}

//check if num n is in tree
bool BinarySearchTree::contains(int n)
{
	if (head == nullptr)
		return false;

	treeNode * current = head;
	while (current->data != n) {
		if (current->right == nullptr && current->left == nullptr)
			return false;
		else if (n < current->data) {
				current = current->left;
		}
		else if (n >= current->data) {
				current = current->right;
		}
	}
	return true;
}

//remove element from tree, update node numeration
void BinarySearchTree::remove(int del_value)
{
	treeNode * current = head;

	if (!contains(del_value))
		throw std::out_of_range("No such element in tree");


	if (head->data == del_value) {
		head = nullptr;
		node_amount--;
		return;
	}

	while (current->left != nullptr || current->right != nullptr){
		if (current->right != nullptr && del_value > current->right->data) {
			current = current->right;
		}
		else if (current->left != nullptr && del_value < current->left->data) {
			current = current->left;
		}
		else
			break;
	}

	treeNode *to_add = nullptr, *to_delete = nullptr;
	if (del_value < current->data) {
		to_delete = current->left;
		to_add = current->left->right;
		current->left = current->left->left;

		//if (current->left != nullptr)
			//update_node_num(current->left->node_num);
	}
	else if (del_value >= current->data) {
		to_delete = current->right;
		to_add = current->right->left;
		current->right = current->right->right;

		//if (current->right != nullptr)
			//update_node_num(current->right->node_num);
	}

	node_amount--;
	if (to_add != nullptr) {
		//update_node_num(to_delete->node_num);
		insert(to_add);
	}
	if(to_delete)
		delete to_delete;
}

//print wrapper
void BinarySearchTree::print() {
	print(head, 0);
}

//print tree horizontally
void BinarySearchTree::print(treeNode *p, int level)
{
		if (p)
		{
			print(p->right, level + 1);
			for (int i = 0; i < level; i++)
				std::cout << "     ";

			std::cout << p->data << "--" << '\n';
			print(p->left, level + 1);
		}
}

TreeIterator * BinarySearchTree::create_bft_iterator()
{
	return new BFT_TreeIterator(node_amount, head);
}

TreeIterator * BinarySearchTree::create_dft_iterator()
{
	return new DFT_TreeIterator(node_amount, head);
}

TreeIterator * BinarySearchTree::create_sort_iterator()
{
	return new DFT_sort_TreeIterator(node_amount, head);
}

size_t BinarySearchTree::getNodeAmount()
{
	return node_amount;
}

//required for derrived classes
TreeIterator::TreeIterator() {
	
}

//check if iteration is not over
bool DFT_TreeIterator::has_next()
{
	//check if changed

	return !callStack.isEmpty();
}

treeNode * DFT_TreeIterator::getCurrent()
{
	return callStack.show_top();
}

//one dft iteration
void DFT_TreeIterator::dft(){
	if (!has_next()) {
		throw std::out_of_range("Iteration has over");
	}

	//get element from call stack
	current = callStack.pop();

	//add left and right nodes to call stack
	if (current->right != nullptr) {
		callStack.push(current->right);
	}
	if (current->left != nullptr) {
		callStack.push(current->left);
	}
}

void DFT_sort_TreeIterator::dft_preorder(treeNode *root){
	if (root != NULL)
	{
		dft_preorder(root->left);
		callQueue.enqueue(root);
		dft_preorder(root->right);
	}
}

DFT_sort_TreeIterator::DFT_sort_TreeIterator(size_t count, treeNode * head)
{
	dft_preorder(head);
	node_amount = count;
}

DFT_sort_TreeIterator::~DFT_sort_TreeIterator()
{
	callQueue.~Queue();
	treeNode* current = nullptr;
	size_t node_amount = 0;
}

bool DFT_sort_TreeIterator::has_next()
{
	return !callQueue.isEmpty();
}

int DFT_sort_TreeIterator::next()
{
	if (!has_next())
		throw std::out_of_range("Iteration has over");
	return callQueue.dequeue()->data;
}

treeNode * DFT_sort_TreeIterator::getCurrent()
{
	return callQueue.top();
}

//initialize dft iterator
DFT_TreeIterator::DFT_TreeIterator(size_t count, treeNode * head)
{
	node_amount = count;
	if (head != nullptr) {
		current = head;
		callStack.push(head);
	}
}

DFT_TreeIterator::~DFT_TreeIterator()
{
	callStack.~Stack();
	treeNode* current = nullptr;
	size_t node_amount = 0;
}

//get current, move next by dft
int DFT_TreeIterator::next()
{
	//treeNode* temp = current;
	treeNode* temp = callStack.show_top();
	dft();
	return temp->data;
}

//initialize btf iterator
BFT_TreeIterator::BFT_TreeIterator(size_t count, treeNode* head)
{
	node_amount = count;
	if (head != nullptr) {
		current = head;
		queue.enqueue(current);
	}
}

BFT_TreeIterator::~BFT_TreeIterator()
{
	queue.~Queue();
	treeNode* current = nullptr;
	size_t node_amount = 0;
}

//one btf iteration
void BFT_TreeIterator::bft()
{
	if (queue.isEmpty()) {
		throw std::out_of_range("Iteration has over");
	}

	//get element from queue
	current = queue.dequeue();

	//add left and right nodes to queue
	if (current->left != nullptr){
		queue.enqueue(current->left);
	}
	if (current->right != nullptr){
		queue.enqueue(current->right);
	}
}

//get current, move next by btf
int BFT_TreeIterator::next() {
	bft();

	return current->data;
}

//check if iteration is not over
bool BFT_TreeIterator::has_next()
{
	return !queue.isEmpty();
}

treeNode * BFT_TreeIterator::getCurrent()
{
	return current;
}

//check array`s equality for tests
bool is_equal(int * const array1, const size_t a1_lines, int * const array2, const size_t a2_lines) {
	//check dimensions
	if (a1_lines != a2_lines)
		return false;

	for (size_t i = 0; i < a1_lines; i++) {
		if (array1[i] != array2[i]) return false;
	}
	return true;
}

treeNode::~treeNode()
{
	treeNode *left = nullptr, *right = nullptr;

	size_t left_space = 0, right_space = 0;
}