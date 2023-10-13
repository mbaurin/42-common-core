#pragma once

#include "reverseIterator.hpp"
#include "vectorIterator.hpp"
#include "utils.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <limits>

namespace ft {
	template<class T, class Alloc = std::allocator<T> >
	class vector {
		public:
			typedef T															value_type;
			typedef Alloc														allocator_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef ft::vector_iterator<value_type, vector>						iterator;
			typedef ft::vector_iterator<const value_type, vector>				const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;
			typedef typename allocator_type::size_type							size_type;

			/*------------------------------- CONSTRUCTOR --------------------------------*/

			vector(const allocator_type & alloc = allocator_type()): _alloc(alloc), _pointer(nullptr), _size(0), _capacity(0) {}
			vector(size_type n, const value_type & val = value_type(), const allocator_type & alloc = allocator_type()): _alloc(alloc), _pointer(nullptr), _size(0), _capacity(0) { assign(n, val); }
			template <class Iter>
			vector(Iter first, Iter last, const allocator_type & alloc = allocator_type()): _alloc(alloc), _pointer(nullptr), _size(0), _capacity(0) { assign(first, last); }
			vector(const vector & cpy): _pointer(nullptr), _size(0), _capacity(0) { *this = cpy; }
			
			/*------------------------------- DESTRUCTOR --------------------------------*/
			
			~vector() {
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_pointer[i]);
				_alloc.deallocate(_pointer, _capacity);
			}

			/*------------------------------- OPERATOR= --------------------------------*/

			vector &operator=(const vector & cpy) {
				_alloc = cpy._alloc;
				assign(cpy.begin(), cpy.end());
				return *this;
			}

		private:
			allocator_type	_alloc;
			pointer			_pointer;
			size_type		_size;
			size_type		_capacity;

		public:

			/*------------------------------- ACCESS --------------------------------*/

			iterator begin() { return _pointer; }
			iterator end() { return _pointer + _size; }
			const_iterator begin() const { return _pointer; }
			const_iterator end() const { return _pointer + _size; }
			reverse_iterator rbegin() { return end(); }
			reverse_iterator rend() { return begin(); }
			const_reverse_iterator rbegin() const { return end(); }
			const_reverse_iterator rend() const { return begin(); }

			reference operator[](size_type n) { return *(begin() + n); }
			const_reference	operator[](size_type n)	const { return *(begin() + n); }
			
			reference front() { return *begin(); }
			reference back() { return *(end() - (_size > 0)); }
			const_reference front() const { return *begin(); }
			const_reference back() const { return *(end() - (_size > 0)); }
			
			reference at(size_type n) {
				if (n >= _size || n < 0)
					throw std::out_of_range("index out of range");
				return _pointer[n];
			}
			const_reference at(size_type n) const {
				if (n >= _size || n < 0)
					throw std::out_of_range("index out of range");
				return _pointer[n];
			}

			allocator_type get_allocator() const { return _alloc; }
	
			/*------------------------------- CAPACITY --------------------------------*/

			size_type size() const { return _size; }
			size_type max_size() const { return _alloc.max_size(); }
			size_type capacity() const { return _capacity; }
			bool empty() const { return _size == 0; }
			void resize(size_type n, value_type val) {
				if (n == _size)
					return ;
				if (n > _size)
					insert(end(), n - _size, val);
				else
					erase(begin() + n, end());
			}
			void reserve(size_type new_capacity) {
				if (!new_capacity || new_capacity <= _capacity)
					return ;
				value_type *tmp = _alloc.allocate(new_capacity);
				for (size_type i = 0; i < _size; i++) {
					_alloc.construct(&tmp[i], _pointer[i]);
					_alloc.destroy(&_pointer[i]);
				}
				_alloc.deallocate(_pointer, _capacity);
				_capacity = new_capacity;
				_pointer = tmp;
			}

			/*------------------------------- ERASE --------------------------------*/

			iterator erase (iterator position) { return erase(position, position + 1); }
			iterator erase (iterator first, iterator last) {
				size_type toErase = ft::distance(first, last);
				if (toErase <= 0)
					return last;
				for (iterator it = first; it != last; it++)
					_alloc.destroy(&(*it));
				if (last == end()) {
					_size -= toErase;
					return end();
				}
				for (iterator it = last; it != end(); it++) {
					_alloc.construct(&(*(it - toErase)), *it);
					_alloc.destroy(&(*it));
				}
				_size -= toErase;
				return first;
			}

			void clear() { erase(begin(), end()); }

			/*------------------------------- INSERT --------------------------------*/

			iterator insert(iterator position, const value_type & val) {
				typename iterator_traits<iterator>::difference_type i = position - begin();
				insert(position, 1, val);
				return (begin() + i);
			}
			void insert(iterator position, size_type n, const value_type & val) {
				size_type nb = n;
				size_type pos = position - begin();
				if (nb <= 0)
					return ;
				while (_size + nb > _capacity) {
					if (_capacity == 0)
						reserve(1);
					else
						reserve(_capacity * 2);
				}
				if (_size > 0) {
					for (size_type i = _size - 1; i >= pos && i != std::numeric_limits<size_type>::max(); i--) {
						_alloc.construct(&_pointer[i + nb], _pointer[i]);
						_alloc.destroy(&_pointer[i]);
					}
				}
				for (size_type i = pos; i < pos + nb; i++)
					_alloc.construct(&_pointer[i], val);
				_size += nb;
			}
			template <class Iter>
			void insert(iterator position, Iter first, Iter last, typename ft::enable_if<!ft::is_integral<Iter>::value, Iter>::type* = nullptr) {
				size_type nb = ft::distance(first, last);
				size_type pos = position - begin();
				if (nb <= 0)
					return ;
				while (_size + nb > _capacity) {
					if (_capacity == 0)
						reserve(1);
					else
						reserve(_capacity * 2);
				}
				if (_size > 0) {
					for (size_type i = _size - 1; i >= pos && i != std::numeric_limits<size_type>::max(); i--) {
						_alloc.construct(&_pointer[i + nb], _pointer[i]);
						_alloc.destroy(&_pointer[i]);
					}
				}
				for (Iter it = first; it != last; it++)
					_alloc.construct(&_pointer[pos++], *it);
				_size += nb;
			}

			/*------------------------------- ASSIGN --------------------------------*/

			template <class Iter>
			void assign (Iter first, Iter last, typename ft::enable_if<!ft::is_integral<Iter>::value, Iter>::type* = nullptr) {
				clear();
				insert(begin(), first, last);
			}
			void assign (size_type n, const value_type & val) {
				clear();
				insert(begin(), n, val);
			}

			/*------------------------------- METHODS --------------------------------*/

			void push_back(const value_type & val) { insert(end(), val); }
			void pop_back() { erase(end() - 1); }

			/*------------------------------- SWAP --------------------------------*/

			void swap(vector & y) {
				std::swap(_alloc, y._alloc);
				std::swap(_pointer, y._pointer);
				std::swap(_size, y._size);
				std::swap(_capacity, y._capacity);
			}

			/*------------------------------- OVERLOAD --------------------------------*/

			void swap(vector &x, vector &y) { x.swap(y); }
			friend bool	operator==(const vector &lhs, const vector &rhs) {
				if (lhs.size() != rhs.size())
					return false;
				return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
			}
			friend bool	operator!=(const vector<T> &lhs, const vector<T> &rhs)	{ return !(lhs == rhs); }
			friend bool operator<(const vector<T> &lhs, const vector<T> &rhs) { return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }
			friend bool	operator<=(const vector<T> &lhs, const vector<T> &rhs) { return !(lhs > rhs); }
			friend bool	operator>(const vector<T> &lhs, const vector<T> &rhs) { return rhs < lhs; }
			friend bool	operator>=(const vector<T> &lhs, const vector<T> &rhs) { return !(lhs < rhs); }
	};
}
