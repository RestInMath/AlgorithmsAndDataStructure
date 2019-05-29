#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include "../RBTree/RBTree_.h"
#include "../AaDS_4sem/Template list.h"

class HuffmanNode {
	std::string letter;
	size_t num;
	HuffmanNode *left = nullptr, *right = nullptr, *parent = nullptr;
	bool code_num = 0;

	friend Node<HuffmanNode*>* find_min_element(List<HuffmanNode*>*);
	friend HuffmanNode* createHuffmanTree(RBTree <char, size_t>* map, List<HuffmanNode*>* leaves);
	friend void getCode(char ch, List<HuffmanNode*>*, std::string*);
	friend std::ostream &operator<<(std::ostream &stream, HuffmanNode l);
	friend void codeHuffman(std::string inc_str);
	friend void showCodes(List<HuffmanNode*>* leaves);
public:
	HuffmanNode() {
		left = nullptr, right = nullptr, parent = nullptr;
	}
	HuffmanNode(std::string c, size_t n) {
		letter = c;
		num = n;
	}
};

std::ostream & operator<<(std::ostream & stream, HuffmanNode l)
{
	stream << l.letter <<  ": " << l.num << '\n';
	return stream;
}

std::string getString() {
	std::string str, out_str;
	do {
		std::getline(std::cin, str);
		out_str.append(str);
		if (str == "")
			break;
	} while (true);
	return out_str;
}

Node<HuffmanNode*>* find_min_element(List<HuffmanNode*>* l) {
	Node<HuffmanNode*> *temp = l->getRoot()->goNext();
	Node<HuffmanNode*> *min_val = l->getRoot();

	while (temp != nullptr) {
		if (temp->value->num < min_val->value->num)
			min_val = temp;

		temp = temp->goNext();
	}
	return min_val;
}

HuffmanNode* createHuffmanTree(RBTree <char, size_t>* map, List<HuffmanNode*>* leaves) {
	//create list of not processed nodes
	List<HuffmanNode*>* current_nodes = new List<HuffmanNode*>();
	
	//fill "leaves" and "current_nodes" lists
	DFT_TreeIterator<char, size_t>* all_nodes = map->create_iterator();
	while (all_nodes->has_next())
	{
		TreeNode<char, size_t> *cur_node = all_nodes->getCurrent();
		HuffmanNode *leaf = new HuffmanNode(std::string(1, cur_node->key), cur_node->value);
		current_nodes->push_back(leaf);
		leaves->push_back(leaf);	
		all_nodes->next();
	}
	
	Node<HuffmanNode*> *left_node = nullptr, *right_node = nullptr;
	HuffmanNode* new_tree_node = nullptr, *root = nullptr;

	while (current_nodes->get_size() > 1) {
		//find two min nodes, delete from current_node list
		left_node = find_min_element(current_nodes);
		current_nodes->remove(left_node);

		right_node = find_min_element(current_nodes);
		current_nodes->remove(right_node);

		//find values of new HuffmanTree node
		std::string new_letters = left_node->value->letter + right_node->value->letter;
		size_t new_num = left_node->value->num + right_node->value->num;

		//add sum node to Huffman tree
		new_tree_node = new HuffmanNode(new_letters, new_num);
		new_tree_node->left = left_node->value;
		new_tree_node->right = right_node->value;
		left_node->value->parent = new_tree_node;
		right_node->value->parent = new_tree_node;
		
		//add edge weight to nodes of Huffman tree
		left_node->value->code_num = 0;
		right_node->value->code_num = 1;
		
		//add sum node "to current_nodes" list
		current_nodes->push_back(new_tree_node);
	}
	return current_nodes->at(0);
}

void getCode(char ch, List<HuffmanNode*>* leaves, std::string* code) {
	Node<HuffmanNode*>* current_node = leaves->getRoot();

	//find leaf with this letter
	while (current_node->value->letter[0] != ch) {
		current_node = current_node->goNext();
		if (current_node == nullptr)
			throw std::exception("No such letter in text");
	}

	//get code by climbing to the root
	HuffmanNode* current_treeNode = current_node->value;
	while (current_treeNode->parent != nullptr) {
		*code += (current_treeNode->code_num ? '1' : '0');
		current_treeNode = current_treeNode->parent;
	};
}

//show codes for every letter
void showCodes(List<HuffmanNode*>* leaves) {
	std::string code;
	Node<HuffmanNode*> *temp = leaves->getRoot();
	while (temp != nullptr) {
		getCode(temp->value->letter[0], leaves, &code);
		std::cout << temp->value->letter[0] << ' ' << code << '\n';
		code = "";
		temp = temp->goNext();
	};
}

void showCodedText(std::string inc_str, List<HuffmanNode*>* leaves) {
	std::string code;
	for (char ch : inc_str) {
		getCode(ch, leaves, &code);
		std::cout << code;

		code = "";
	}

}

//show coded incoming string
void codeHuffman(std::string inc_str) {
	RBTree<char, size_t> *map = new RBTree<char, size_t>();

	//create freq table
	for (char ch : inc_str) {
		try {
			size_t cur_val = map->find(ch);
			map->insert(ch, cur_val + 1);
		}
		catch (std::exception e) {
			map->insert(ch, 1);
		}
	}

	//show freq table
	map->print_map();
	
	//list of HuffmanTree leaves
	List<HuffmanNode*>* leaves = new List<HuffmanNode*>();

	HuffmanNode *tree_root = createHuffmanTree(map, leaves);

	showCodes(leaves);

	std::cout << '\n';

	showCodedText(inc_str, leaves);

}