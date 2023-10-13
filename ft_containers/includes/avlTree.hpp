#pragma once

#include "avlIterator.hpp"
#include "pair.hpp"
#include "map.hpp"

namespace ft
{
	template <typename U, typename V>
	class avlNode
	{
	private:
		ssize_t	_height;

	public:
		typedef ft::pair<U, V>	value_type;

		value_type	value;
		avlNode		*parent;
		avlNode		*left;
		avlNode		*right;

		/*------------------------------- CONSTRUCTOR --------------------------------*/

		avlNode(const value_type &value): _height(1), value(value), left(nullptr), right(nullptr) {}

		/*------------------------------- UTILS FOR AVL MATH --------------------------------*/

		avlNode	*getMax() { 
			if (right)
				return (right->getMax());
			else
				return this;
		}
		avlNode	*getMin() { 
			if (left)
				return (left->getMin());
			else
				return this;
		}
		void updateHeight() {
			int param1;
			int param2;
			if (right)
				param1 = right->height();
			else
				param1 = 0;
			if (left)
				param2 = left->height();
			else
				param2 = 0;
			_height = 1 + std::max(param1, param2);
		}
		ssize_t	balance() const {
			ssize_t tmp1;
			ssize_t tmp2;
			if (left)
				tmp1 = left->height();
			else
				tmp1 = 0;
			if (right)
				tmp2 = right->height();
			else
				tmp2 = 0;
			return (tmp1 - tmp2);
		}
		ssize_t	height() const { return _height; }
	};

	template <typename U, typename V, class Node = avlNode<U, V>, class nodeAlloc = std::allocator<Node> >
	class avlTree
	{
	public:
		typedef ft::pair<U, V>										value_type;
		typedef Node												node_type;
		typedef Node												*node_pointer;
		typedef typename nodeAlloc::template rebind<Node>::other	node_alloc;
		typedef ft::avl_iterator<Node>								iterator;
		typedef ft::avl_iterator<Node>								const_iterator;
		typedef typename node_alloc::size_type						size_type;

		node_alloc 		_alloc;
		node_pointer	_root;
		size_t			_size;

		/*------------------------------- CONSTRUCTOR --------------------------------*/

		avlTree(const node_alloc& _node_alloc = node_alloc()) : _alloc(_node_alloc), _root(nullptr), _size(0) {}

		/*------------------------------- DESTRUCTOR --------------------------------*/

		~avlTree() { clearTree(); }

		/*------------------------------- GETTERS --------------------------------*/

		size_type getSize() const { return _size; }
		node_pointer getRoot() const { return _root; }

		/*------------------------------- CAPACITY --------------------------------*/

		size_type max_size() const { return _alloc.max_size(); }
		bool isEmpty() const { return _root == nullptr; }

		/*------------------------------- METHODS --------------------------------*/

		node_pointer find(value_type value) const { return find(value, _root); }
		void insert(value_type value) { 
			_root = insert(value, _root);
			resetParents();
		}
		void remove(value_type value) {
			_root = remove(value, _root);
			resetParents();
		}
		void clearTree() {
			clearTree(_root);
			_size = 0;
			_root = nullptr;
		}

		/*------------------------------- ACCESS --------------------------------*/

		iterator begin() {
			if (_root)
				return (iterator(_root->getMin(), _root->getMin(), _root->getMax()));
			else
				return iterator();
		}
		const_iterator begin() const {
			if (_root)
				return (const_iterator(_root->getMin(), _root->getMin(), _root->getMax()));
			else
				return const_iterator();
		}
		iterator end() {
			if (_root)
				return (iterator(nullptr, _root->getMin(), _root->getMax()));
			else
				return iterator();
		}
		const_iterator end() const {
			if (_root)
				return (const_iterator(nullptr, _root->getMin(), _root->getMax()));
			else
				return const_iterator();
		}

		/*------------------------------- SWAP --------------------------------*/

		void	swap(avlTree &x) {
			node_type *tmp = _root;
			_root = x._root;
			x._root = tmp;
			node_alloc 	tmpa = _alloc;
			_alloc = x._alloc;
			x._alloc = tmpa;
			size_t	tmps = _size;
			_size = x._size;
			x._size = tmps;
		}

	private:

		/*------------------------------- FIND --------------------------------*/

		node_pointer find(value_type value, node_type *node) const {
			if (node == nullptr)
				return nullptr;
			if (node->value.first < value.first)
				return find(value, node->right);
			if (node->value.first > value.first)
				return find(value, node->left);
			return node;
		}

		/*------------------------------- INSERT --------------------------------*/

		node_pointer insert(value_type value, node_type *node) {
			if (node == nullptr) {
				node_pointer	new_node = _alloc.allocate(1);
				_alloc.construct(new_node, node_type(value));
				_size++;
				return new_node;
			}
			if (node->value.first < value.first)
				node->right = insert(value, node->right);
			else if (node->value.first > value.first)
				node->left = insert(value, node->left);
			else
				return node;
			node->updateHeight();
			return applyRotation(node);
		}

		/*------------------------------- ROTATIONS --------------------------------*/

		node_pointer applyRotation(node_type *node) {
			ssize_t	balance = node->balance();
			if (balance > 1) {
				if (node->left && node->left->balance() < 0)
					node->left = leftRotation(node->left);
				return rightRotation(node);
			}
			if (balance < -1) {
				if (node->right && node->right->balance() > 0)
					node->right = rightRotation(node->right);
				return leftRotation(node);
			}
			return node;
		}
		node_pointer leftRotation(node_type *node) {
			node_pointer rightNode = node->right;
			node_pointer centerNode = rightNode->left;
			rightNode->left = node;
			node->right = centerNode;
			node->updateHeight();
			rightNode->updateHeight();
			return rightNode;
		}
		node_pointer rightRotation(node_type *node) {
			node_pointer leftNode = node->left;
			node_pointer centerNode = leftNode->right;
			leftNode->right = node;
			node->left = centerNode;
			node->updateHeight();
			leftNode->updateHeight();
			return leftNode;
		}

		/*------------------------------- REMOVE / CLEAR TREE --------------------------------*/

		node_pointer remove(value_type value, node_type *node) {
			if (node == nullptr)
				return nullptr;
			if (node->value.first > value.first)
				node->left = remove(value, node->left);
			else if (node->value.first < value.first)
				node->right = remove(value, node->right);
			else {
				node_pointer	tmp;
				if (node->left == nullptr) {
					tmp = node->right;
					_alloc.destroy(node);
					_alloc.deallocate(node, 1);
					_size--;
					return tmp;
				} else if (node->right == nullptr) {
					tmp = node->left;
					_alloc.destroy(node);
					_alloc.deallocate(node, 1);
					_size--;
					return tmp;
				}
				node->value = node->left->getMax()->value;
				node->left = remove(node->value, node->left);
			}
			node->updateHeight();
			return applyRotation(node);
		}

		void resetParents() {
			if (!_root)
				return;
			_root->parent = nullptr;
			resetParents(_root);
		}
		void resetParents(node_type *node) {
			if (node == nullptr)
				return ;
			if (node->left)
				node->left->parent = node;
			if (node->right)
				node->right->parent = node;
			resetParents(node->left);
			resetParents(node->right);
		}
		
		void clearTree(node_type *node) {
			if (node == nullptr)
				return ;
			clearTree(node->left);
			clearTree(node->right);
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
		}
	};
};
