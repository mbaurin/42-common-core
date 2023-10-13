#pragma once

#include "utilsIterator.hpp"

namespace ft
{
	template <typename T, typename Container>
	class vector_iterator
	{
	public:
		typedef typename iterator_traits<T *>::difference_type	difference_type;
		typedef typename iterator_traits<T *>::value_type		value_type;
		typedef typename iterator_traits<T *>::pointer			pointer;
		typedef typename iterator_traits<T *>::reference		reference;
		typedef typename ft::random_access_ierator_tag			iterator_category;

		/*------------------------------- CONSTRUCTOR --------------------------------*/

		vector_iterator(): _pointer(nullptr) {}
		vector_iterator(T *addr): _pointer(addr) {}
		template <typename U>
		vector_iterator(const vector_iterator<U, Container> &cpy): _pointer(cpy.base()) {}
		
		/*------------------------------- DESTRUCTOR --------------------------------*/

		~vector_iterator() {}

		/*------------------------------- ACCESS --------------------------------*/

		pointer base() const { return (_pointer); }

		/*------------------------------- OPERATORS --------------------------------*/

		vector_iterator &operator=(const vector_iterator &rhs) {
			_pointer = rhs._pointer;
			return *this;
		}
		vector_iterator &operator++() {
			++_pointer;
			return *this;
		}
		vector_iterator operator++(int) {
			vector_iterator cpy(_pointer++);
			return cpy;
		}
		vector_iterator &operator--() {
			--_pointer;
			return *this;
		}
		vector_iterator operator--(int) {
			vector_iterator cpy(_pointer--);
			return cpy;
		}
		reference operator*() const { return (*_pointer); }
		pointer operator->() const { return (_pointer); }
		vector_iterator &operator+=(difference_type rhs) {
			_pointer += rhs;
			return *this;
		}
		vector_iterator &operator-=(difference_type rhs) {
			_pointer -= rhs;
			return *this;
		}
		reference operator[](difference_type rhs) const { return *(_pointer + rhs); }

	private:
		pointer	_pointer;
	};
}

namespace ft {
	template <typename T, typename Container>
	bool operator==(const ft::vector_iterator<T, Container> &rhs, const ft::vector_iterator<T, Container> &lhs)	{ return (lhs.base() == rhs.base()); }
	template <typename U, typename V, typename Container>
	bool operator==(const ft::vector_iterator<U, Container> &rhs, const ft::vector_iterator<V, Container> &lhs)	{ return (lhs.base() == rhs.base()); }
	template <typename T, typename Container>
	bool operator!=(const ft::vector_iterator<T, Container> &rhs, const ft::vector_iterator<T, Container> &lhs)	{ return (lhs.base() != rhs.base()); }
	template <typename U, typename V, typename Container>
	bool operator!=(const ft::vector_iterator<U, Container> &rhs, const ft::vector_iterator<V, Container> &lhs)	{ return (lhs.base() != rhs.base()); }
	template <typename T, typename Container>
	bool operator>=(const ft::vector_iterator<T, Container> &rhs, const ft::vector_iterator<T, Container> &lhs) { return (lhs.base() <= rhs.base()); }
	template <typename U, typename V, typename Container>
	bool operator>=(const ft::vector_iterator<U, Container> &rhs, const ft::vector_iterator<V, Container> &lhs)	{ return (lhs.base() <= rhs.base()); }
	template <typename T, typename Container>
	bool operator<=(const ft::vector_iterator<T, Container> &rhs, const ft::vector_iterator<T, Container> &lhs)	{ return (lhs.base() >= rhs.base()); }
	template <typename U, typename V, typename Container>
	bool operator<=(const ft::vector_iterator<U, Container> &rhs, const ft::vector_iterator<V, Container> &lhs) { return (lhs.base() >= rhs.base()); }
	template <typename T, typename Container>
	bool operator>(const ft::vector_iterator<T, Container> &rhs, const ft::vector_iterator<T, Container> &lhs) { return (lhs.base() < rhs.base()); }
	template <typename U, typename V, typename Container>
	bool operator>(const ft::vector_iterator<U, Container> &rhs, const ft::vector_iterator<V, Container> &lhs) { return (lhs.base() < rhs.base()); }
	template <typename T, typename Container>
	bool operator<(const ft::vector_iterator<T, Container> &rhs, const ft::vector_iterator<T, Container> &lhs) { return (lhs.base() > rhs.base()); }
	template <typename U, typename V, typename Container>
	bool operator<(const ft::vector_iterator<U, Container> &rhs, const ft::vector_iterator<V, Container> &lhs) { return (lhs.base() > rhs.base()); }
	template <typename T, typename Container>
	ft::vector_iterator<T, Container> operator+(typename ft::vector_iterator<T, Container>::difference_type rhs, const ft::vector_iterator<T, Container> &lhs) { return (lhs.base() + rhs); }
	template <typename T, typename Container>
	ft::vector_iterator<T, Container> operator+(const ft::vector_iterator<T, Container> &rhs, typename ft::vector_iterator<T, Container>::difference_type lhs) { return (rhs.base() + lhs); }
	template <typename T, typename Container>
	ft::vector_iterator<T, Container> operator-(const ft::vector_iterator<T, Container> &rhs, typename ft::vector_iterator<T, Container>::difference_type lhs) { return (rhs.base() - lhs); }
	template <typename T, typename Container>
	typename ft::vector_iterator<T, Container>::difference_type operator-(const ft::vector_iterator<T, Container> &rhs, const ft::vector_iterator<T, Container> &lhs) { return (rhs.base() - lhs.base()); }
	template <typename U, typename V, typename Container>
	typename ft::vector_iterator<U, Container>::difference_type operator-(const ft::vector_iterator<V, Container> &rhs, const ft::vector_iterator<U, Container> &lhs) { return (rhs.base() - lhs.base()); }
}
