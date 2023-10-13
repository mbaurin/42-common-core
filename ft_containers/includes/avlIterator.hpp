#pragma once

#include "utilsIterator.hpp"
#include "avlTree.hpp"

namespace ft
{
	template <typename T>
	class avl_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
	public :
		typedef typename T::value_type																	value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;

		/*------------------------------- CONSTRUCTOR --------------------------------*/

		avl_iterator(): _node(), _firstNode(), _lastNode(), _end(false) {}
		avl_iterator(T *node, T *firstNode, T *lastNode): _node(node), _firstNode(firstNode), _lastNode(lastNode), _end(node == nullptr) {}
		template <typename U>
		avl_iterator(const avl_iterator<U> &avlIter): _node(avlIter._node), _firstNode(avlIter._firstNode), _lastNode(avlIter._lastNode), _end(avlIter._end == nullptr) {}
		
		/*------------------------------- DESTRUCTOR --------------------------------*/

		~avl_iterator() {}

		/*------------------------------- OPERATOR --------------------------------*/

		pointer base() const { return &_node->value; }

		avl_iterator &operator=(const avl_iterator &src) {
			_node = src._node;
			_firstNode = src._firstNode;
			_lastNode = src._lastNode;
			_end = src._end;
			return *this;
		}
		reference operator*() const { return _node->value; }
		pointer operator->() const { return &_node->value; }
		avl_iterator &operator++() {
			T *tmp;
			if (!_node)
				return *this;
			if (!_node->right) {
				if (_node == _lastNode) {
					_end = true;
					_node = nullptr;
					return *this;
				}
				tmp = _node;
				_node = _node->parent;
				while (_node->right && tmp == _node->right) {
					tmp = _node;
					_node = _node->parent;
				}
				return *this;
			}
			_node = _node->right;
			while (_node->left)
				_node = _node->left;
			return *this;
		}
		avl_iterator operator++(int) {
			avl_iterator tmp(*this);
			++*this;
			return tmp;
		}
		avl_iterator &operator--() {
			T *tmp;
			if (!_node && _end) {
				_node = _lastNode;
				_end = false;
				return *this;
			}
			if (!_node)
				return *this;
			if (!_node->left) {
				if (_node == _firstNode) {
					_node = nullptr;
					return *this;
				}
				tmp = _node;
				_node = _node->parent;
				while (_node->left && tmp == _node->left) {
					tmp = _node;
					_node = _node->parent;
				}
				return *this;
			}
			_node = _node->left;
			while (_node->right)
				_node = _node->right;
			return *this;
		}
		avl_iterator operator--(int) {
			avl_iterator tmp(*this);
			--*this;
			return tmp;
		}

		T		*_node;
		T		*_firstNode;
		T		*_lastNode;
		bool	_end;
	};

	template <typename T>
	bool operator==(const ft::avl_iterator<T> &rhs,	const ft::avl_iterator<T> &lhs) { return rhs._node == lhs._node; }
	template <typename U, typename V>
	bool operator==(const ft::avl_iterator<U> &rhs, const ft::avl_iterator<V> &lhs) { return rhs._node == lhs._node; }
	template <typename T>
	bool operator!=(const ft::avl_iterator<T> &rhs,	const ft::avl_iterator<T> &lhs) { return rhs._node != lhs._node; }
	template <typename U, typename V>
	bool operator!=(const ft::avl_iterator<U> &rhs, const ft::avl_iterator<V> &lhs) { return rhs._node = lhs._node; }
}
