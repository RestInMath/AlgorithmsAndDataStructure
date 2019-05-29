#pragma once
#include "../AaDS_4sem/Template list.h"
#include "Tree iterator.h"

enum {RED, BLACK};

template <typename key_type, typename value_type>
class RBTree;

//lab4
class route;

template<typename key_type, typename value_type>
class TreeNode{
	friend class RBTree<key_type, value_type>;
	friend class DFT_TreeIterator<key_type, value_type>;
	friend class DFT_sort_TreeIterator<typename key_type, typename value_type>;
	friend HuffmanNode* createHuffmanTree(RBTree <char, size_t>*, List<HuffmanNode*>* leaves);
	friend void codeHuffman(std::string inc_str);
	friend std::string find_min_new_route(RBTree<std::string, List<route>*>* map, RBTree<std::string, int>* city_routes, List<std::string>* visited);
	friend std::string find_min_new_route(RBTree<std::string, List<route>*>* map, RBTree<std::string, int>* city_routes, List<std::string>* visited);
	//friend void fillEmptyRoutes(RBTree<std::string, List<route>*>* map);
private:
	key_type key;
	value_type value;
	int color = BLACK;
	TreeNode<key_type, value_type> *left = nullptr, *right = nullptr, *parent = nullptr;

public:
	TreeNode();
	TreeNode(key_type, value_type);
	bool isNIL();
};

template <typename key_type, typename value_type>
class RBTree {
	TreeNode<key_type, value_type> *root = new TreeNode<key_type, value_type>();
	
	size_t node_amount = 0;

	void insertion_case1(TreeNode<key_type, value_type>*);
	void insertion_case2(TreeNode<key_type, value_type>*);
	void insertion_case3(TreeNode<key_type, value_type>*);
	void insertion_case4(TreeNode<key_type, value_type>*);

	TreeNode<key_type, value_type> * grandparent(TreeNode<key_type, value_type> *);
	TreeNode<key_type, value_type> * uncle(TreeNode<key_type, value_type> *);
	TreeNode<key_type, value_type> * brother(TreeNode<key_type, value_type> *);

	void rotate_left(TreeNode<key_type, value_type>*);
	void rotate_right(TreeNode<key_type, value_type>*);

	void swap_nodes(TreeNode<key_type, value_type> *, TreeNode<key_type, value_type> *);
	void skip_node(TreeNode<key_type, value_type> * n, TreeNode<key_type, value_type> * child);
	TreeNode<key_type, value_type>* find_next_key(TreeNode<key_type, value_type> * n);
	void correct_tree(TreeNode<key_type, value_type>*);

	void delete_case1(TreeNode<key_type, value_type>*);
	void delete_case2(TreeNode<key_type, value_type>*);
	void delete_case3(TreeNode<key_type, value_type>*);
	void delete_case4(TreeNode<key_type, value_type>*);
	void delete_case5(TreeNode<key_type, value_type>*);
	void delete_case6(TreeNode<key_type, value_type>*);

public:
	RBTree();
	~RBTree();

	void insert(key_type, value_type);
	void delete_node(key_type);
	value_type find(key_type);
	void clear();
	List<key_type>* get_keys();
	List<value_type>* get_values();
	DFT_TreeIterator<key_type, value_type>* create_iterator();
	DFT_sort_TreeIterator<key_type, value_type>* create_sort_iterator();
	void print();
	void print(TreeNode<key_type, value_type>*, size_t level);
	void print_map();
	void print_map(TreeNode<key_type, value_type>*);
	size_t getNodeAmount();
};

//NIL constructor
template<typename key_type, typename value_type>
inline TreeNode<key_type, value_type>::TreeNode()
{
	
}

//RED node to add
template<typename key_type, typename value_type>
inline TreeNode<key_type, value_type>::TreeNode(key_type new_key, value_type new_value)
{
	this->key = new_key;
	this->value = new_value;
	this->color = RED;
	this->left = new TreeNode<key_type, value_type>;
	this->right = new TreeNode<key_type, value_type>;
}

//insertion cases
template<typename key_type, typename value_type>
inline void RBTree<key_type, value_type>::insertion_case1(TreeNode<key_type, value_type> * current)
{
	if (current->parent == nullptr) {
		current->color = BLACK;
	}
	else
		insertion_case2(current);

}

template<typename key_type, typename value_type>
inline void RBTree<key_type, value_type>::insertion_case2(TreeNode<key_type, value_type> * current)
{
	if (current->parent->color == BLACK)
		return;

	TreeNode<key_type, value_type> *u = uncle(current), *g;

	if ((!u->isNIL()) && (current->parent->color == RED) && (u->color == RED)) {
		current->parent->color = BLACK;
		u->color = BLACK;
		g = grandparent(current);
		g->color = RED;
		insertion_case1(g);
	}
	else {
		insertion_case3(current);
	}

}

template<typename key_type, typename value_type>
inline void RBTree<key_type, value_type>::insertion_case3(TreeNode<key_type, value_type>* n)
{
	TreeNode<key_type, value_type> *g = grandparent(n);

	if ((n == n->parent->right) && (n->parent == g->left)) {
		rotate_left(n->parent);

		n = n->left;
	}
	else if ((n == n->parent->left) && (n->parent == g->right)) {
		rotate_right(n->parent);

		n = n->right;
	}
	insertion_case4(n);
}

template<typename key_type, typename value_type>
inline void RBTree<key_type, value_type>::insertion_case4(TreeNode<key_type, value_type>* n)
{
	TreeNode<key_type, value_type> *g = grandparent(n);

	n->parent->color = BLACK;
	g->color = RED;
	if ((n == n->parent->left) && (n->parent == g->left)) {
		rotate_right(g);
	}
	else if( (n == n->parent->right) && (n->parent == g->right)){
		rotate_left(g);
	}
}

//getters
template<typename key_type, typename value_type>
inline TreeNode<key_type, value_type>*
RBTree<key_type, value_type>::grandparent(TreeNode<key_type, value_type>* node)
{
	if ((!node->isNIL()) && (!node->parent->isNIL()))
		return node->parent->parent;
	else
		return nullptr;
}

template<typename key_type, typename value_type>
inline TreeNode<key_type, value_type>*
RBTree<key_type, value_type>::uncle(TreeNode<key_type, value_type>* n)
{
	TreeNode<key_type, value_type> *g = grandparent(n);
	if (g == nullptr)
		return nullptr; // No grandparent means no uncle
	if (n->parent == g->left)
		return g->right;
	else
		return g->left;
}

template<typename key_type, typename value_type>
inline TreeNode<key_type, value_type>* RBTree<key_type, value_type>::brother(TreeNode<key_type, value_type>* n)
{
	if (n == n->parent->left)
		return n->parent->right;
	else
		return n->parent->left;
}

//rotations
template<typename key_type, typename value_type>
inline void RBTree<key_type, value_type>::rotate_left(TreeNode<key_type, value_type>* n)
{
	TreeNode<key_type, value_type> *pivot = n->right;

	pivot->parent = n->parent;
	if (n->parent != nullptr) {
		if (n->parent->left == n)
			n->parent->left = pivot;
		else
			n->parent->right = pivot;
	}
	else
		root = pivot;

	n->right = pivot->left;
	if (!pivot->left->isNIL())
		pivot->left->parent = n;

	n->parent = pivot;
	pivot->left = n;
}

template<typename key_type, typename value_type>
inline void RBTree<key_type, value_type>::rotate_right(TreeNode<key_type, value_type>* n)
{
	TreeNode<key_type, value_type> *pivot = n->left;

	pivot->parent = n->parent;
	if (n->parent != nullptr) {
		if (n->parent->left == n)
			n->parent->left = pivot;
		else
			n->parent->right = pivot;
	}
	else
		root = pivot;

	n->left = pivot->right;
	if (!pivot->right->isNIL())
		pivot->right->parent = n;

	n->parent = pivot;
	pivot->right = n;
}

template<typename key_type, typename value_type>
inline void RBTree<key_type, value_type>::swap_nodes(TreeNode<key_type, value_type>* first, TreeNode<key_type, value_type>* second)
{
	key_type temp_key = first->key;
	value_type temp_value = first->value;
	
	first->key = second->key;
	first->value = second->value;

	second->key = temp_key;
	second->value = temp_value;
}

template<typename key_type, typename value_type>
inline void RBTree<key_type, value_type>::skip_node(TreeNode<key_type, value_type>* n, TreeNode<key_type, value_type>* child)
{
	if (n == root) {
		root = child;
	}
	else if (n->parent->left == n) {
		n->parent->left = child;
	}
	else {
		n->parent->right = child;
	}
}

template<typename key_type, typename value_type>
inline TreeNode<key_type, value_type>* RBTree<key_type, value_type>::find_next_key(TreeNode<key_type, value_type>* n)
{
	//find node with one child
	n = n->right;
	if(!n->isNIL())
		while (!n->left->isNIL()) {
			n = n->left;
		}
	return n;
}

template<typename key_type, typename value_type>
inline void RBTree<key_type, value_type>::correct_tree(TreeNode<key_type, value_type>* n)
{

	TreeNode < key_type, value_type> *s = brother(n);

	//delete_case2
	if (s->color == RED) {
		n->parent->color = RED;
		s->color = BLACK;
		if (n == n->parent->left)
			rotate_left(n->parent);
		else
			rotate_right(n->parent);
	}
	delete_case3(n);

}

template<typename key_type, typename value_type>
inline void RBTree<key_type, value_type>::delete_case1(TreeNode<key_type, value_type> * n)
{
	if (n->parent != nullptr)
		delete_case2(n);
}

template<typename key_type, typename value_type>
inline void RBTree<key_type, value_type>::delete_case2(TreeNode<key_type, value_type>* n)
{
	TreeNode < key_type, value_type> *s = brother(n);
	

	if (s->color == RED) {
		n->parent->color = RED;
		s->color = BLACK;
		if (n == n->parent->left)
			rotate_left(n->parent);
		else
			rotate_right(n->parent);
	}
	delete_case3(n);
}

template<typename key_type, typename value_type>
inline void RBTree<key_type, value_type>::delete_case3(TreeNode<key_type, value_type>* n)
{
	TreeNode<key_type, value_type> *s = brother(n);

	if ((n->parent->color == BLACK) &&
		(s->color == BLACK) &&
		(s->left->color == BLACK) &&
		(s->right->color == BLACK)) {
		s->color = RED;
		delete_case1(n->parent);
	}
	else
		delete_case4(n);
}

template<typename key_type, typename value_type>
inline void RBTree<key_type, value_type>::delete_case4(TreeNode<key_type, value_type>* n)
{
	TreeNode<key_type, value_type> *s = brother(n);

	if ((n->parent->color == RED) &&
		(s->color == BLACK) &&
		(s->left->color == BLACK) &&
		(s->right->color == BLACK)) {
		s->color = RED;
		n->parent->color = BLACK;
	}
	else
		delete_case5(n);
}

template<typename key_type, typename value_type>
inline void RBTree<key_type, value_type>::delete_case5(TreeNode<key_type, value_type>* n)
{
	TreeNode<key_type, value_type> *s = brother(n);

	if (s->color == BLACK) { /* this if statement is trivial,
							 due to case 2 (even though case 2 changed the sibling to a sibling's child,
							 the sibling's child can't be red, since no red parent can have a red child). */
							 /* the following statements just force the red to be on the left of the left of the parent,
							 or right of the right, so case six will rotate correctly. */
		if ((n == n->parent->left) &&
			(s->right->color == BLACK) &&
			(s->left->color == RED)) { /* this last test is trivial too due to cases 2-4. */
			s->color = RED;
			s->left->color = BLACK;
			rotate_right(s);
		}
		else if ((n == n->parent->right) &&
			(s->left->color == BLACK) &&
			(s->right->color == RED)) {/* this last test is trivial too due to cases 2-4. */
			s->color = RED;
			s->right->color = BLACK;
			rotate_left(s);
		}
	}
	delete_case6(n);
}

template<typename key_type, typename value_type>
inline void RBTree<key_type, value_type>::delete_case6(TreeNode<key_type, value_type>* n)
{
	TreeNode<key_type, value_type> *s = brother(n);

	s->color = n->parent->color;
	n->parent->color = BLACK;

	if (n == n->parent->left) {
		s->right->color = BLACK;
		rotate_left(n->parent);
	}
	else {
		s->left->color = BLACK;
		rotate_right(n->parent);
	}
}


template<typename key_type, typename value_type>
inline RBTree<key_type, value_type>::RBTree()
{

}

template<typename key_type, typename value_type>
inline RBTree<key_type, value_type>::~RBTree()
{
	clear();
}

template<typename key_type, typename value_type>
inline void RBTree<key_type, value_type>::insert(key_type new_key, value_type new_value)
{
	if (root->isNIL()) {
		root = new TreeNode<key_type, value_type>(new_key, new_value);
		node_amount++;
		insertion_case1(root);
		return;
	}

	TreeNode<key_type, value_type> * current = root;
	while (true) {
		if (new_key < current->key) {
			if (current->left->isNIL()) {
				current->left = new TreeNode<key_type, value_type>(new_key, new_value);
				current->left->parent = current;
				insertion_case1(current->left);
				node_amount++;
				return;
			}
			else {
				current = current->left;
			}
		}
		else if(new_key >= current->key){
			if (new_key == current->key) {
				current->value = new_value;
				break;
			}
			else if (current->right->isNIL()) {
				current->right = new TreeNode<key_type, value_type>(new_key, new_value);
				current->right->parent = current;
				insertion_case1(current->right);
				node_amount++;
				return;
			}
			else {
				current = current->right;
			}
		}
	}
}

template<typename key_type, typename value_type>
inline void RBTree<key_type, value_type>::delete_node(key_type del_key)
{
	if (node_amount == 0)
		throw std::exception("Trying to delete node from empty tree");

	if (node_amount == 1) {
		root = new TreeNode<key_type, value_type>;
		node_amount--;
		return;
	}

	TreeNode<key_type, value_type> * current = root;
	//find node to delete
	//throw ex in case of no key
	while (!current->left->isNIL() || !current->right->isNIL()) {
		if (!current->right->isNIL() && del_key > current->key) {
			current = current->right;
		}
		else if (!current->left->isNIL() && del_key < current->key) {
			current = current->left;
		}
		if (current->key == del_key) {

			//check if node has two children
			if (!current->left->isNIL() && !current->right->isNIL()) {
				TreeNode<key_type, value_type> *next_key = find_next_key(current);
				swap_nodes(next_key, current);
				current = next_key;
			}
			
			TreeNode<key_type, value_type> *child = (current->left->isNIL() ? current->right : current->left);
			skip_node(current, child);
			if (current->color == BLACK) {
				if (child->color == RED)
					child->color = BLACK;
				else
					correct_tree(child);
			}

			node_amount--;
			return;
		}
	}
	throw std::exception("Trying to delete absent node");
}

template<typename key_type, typename value_type>
inline value_type RBTree<key_type, value_type>::find(key_type del_key)
{
	TreeNode<key_type, value_type> * current = root;

	//kostbl/\b
	if (root->isNIL()) {
		throw std::exception("No such element in map");
	}

	while (current->key != del_key) {
		if (current->isNIL())
			throw std::exception("No such element in map");
		else if (del_key < current->key) {
			current = current->left;
		}
		else if (del_key >= current->key) {
			current = current->right;
		}
	}
	return current->value;
}

template<typename key_type, typename value_type>
inline void RBTree<key_type, value_type>::clear()
{
	if (!root->isNIL())
	{
		DFT_sort_TreeIterator<key_type, value_type> * iterator = create_sort_iterator();
		TreeNode<key_type, value_type> * last;
		while (iterator->has_next())
		{
			last = iterator->getCurrent();
			iterator->next();
			delete last;
		}
		delete iterator;
	}

	root = new TreeNode<key_type, value_type>();

	node_amount = 0;
}

template<typename key_type, typename value_type>
inline List<key_type>* RBTree<key_type, value_type>::get_keys()
{
	DFT_TreeIterator<key_type, value_type>* it = create_iterator();
	List<key_type> *keys = new List<key_type>();
	while (it->has_next()) {
		keys->push_back(it->next());
	}
	return keys;
}

template<typename key_type, typename value_type>
inline List<value_type>* RBTree<key_type, value_type>::get_values()
{
	DFT_TreeIterator<key_type, value_type>* it = create_iterator();
	List<value_type> *values = new List<value_type>();
	while (it->has_next()) {
		values->push_back(it->next_val());
	}
	return values;
}

template<typename key_type, typename value_type>
inline DFT_TreeIterator<key_type, value_type>* RBTree<key_type, value_type>::create_iterator()
{
	return new DFT_TreeIterator<key_type, value_type>(node_amount, root);
}

template<typename key_type, typename value_type>
inline DFT_sort_TreeIterator<key_type, value_type>* RBTree<key_type, value_type>::create_sort_iterator()
{
	return new DFT_sort_TreeIterator<key_type, value_type>(node_amount, root);
}

template<typename key_type, typename value_type>
inline void RBTree<key_type, value_type>::print()
{
	print(root, 0);
}

template<typename key_type, typename value_type>
inline void RBTree<key_type, value_type>::print(TreeNode<key_type, value_type> *p, size_t level)
{
	if (p) {
		print(p->right, level + 1);
		for (int i = 0; i < level; i++)
			std::cout << "     ";

		std::cout << p->key << ": " << p->value << "--" << '\n';
		print(p->left, level + 1);
	}
}

template<typename key_type, typename value_type>
inline void RBTree<key_type, value_type>::print_map()
{
	print_map(root);
}

template<typename key_type, typename value_type>
inline void RBTree<key_type, value_type>::print_map(TreeNode<key_type, value_type>* p)
{
	if (!p->isNIL() && p != nullptr) {
		print_map(p->right);
		std::cout << p->key << ": " << p->value << '\n';
		print_map(p->left);
	}
}

template<typename key_type, typename value_type>
inline size_t RBTree<key_type, value_type>::getNodeAmount()
{
	return node_amount;
}

template<typename key_type, typename value_type>
inline bool TreeNode<key_type, value_type>::isNIL()
{
	return (this != nullptr) && (this->right == nullptr) && (this->left == nullptr) && (this->color == BLACK);
}