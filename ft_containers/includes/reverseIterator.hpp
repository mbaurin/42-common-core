#pragma once

#include "utilsIterator.hpp"

namespace ft
{
	template <typename Iter>
	class reverse_iterator
	{
	public:
		typedef typename iterator_traits<Iter>::difference_type		difference_type;
		typedef typename iterator_traits<Iter>::value_type			value_type;
		typedef typename iterator_traits<Iter>::pointer				pointer;
		typedef typename iterator_traits<Iter>::reference			reference;
		typedef typename iterator_traits<Iter>::iterator_category	iterator_category;

		/*------------------------------- CONSTRUCTOR --------------------------------*/

		reverse_iterator(): _iterator() {}
		reverse_iterator(Iter iter): _iterator(iter) {}
		template <typename U>
		reverse_iterator(const reverse_iterator<U> &rhs): _iterator(rhs.base()) {}

		/*------------------------------- DESTRUCTOR --------------------------------*/
		
		~reverse_iterator() {}

		/*------------------------------- ACCESS --------------------------------*/
		
		Iter base() const { return (_iterator); }

		/*------------------------------- OPERATORS --------------------------------*/

		reverse_iterator<Iter> &operator=(const reverse_iterator<Iter> &rhs) {
			_iterator = rhs._iterator;
			return *this;
		}
		reverse_iterator<Iter> &operator++() {
			--_iterator;
			return *this;
		}
		reverse_iterator<Iter> operator++(int) {
			reverse_iterator<Iter> cpy(_iterator--);
			return cpy;
		}
		reverse_iterator<Iter> &operator--() {
			++_iterator;
			return *this;
		}
		reverse_iterator<Iter> operator--(int) {
			reverse_iterator<Iter> cpy(_iterator++);
			return cpy;
		}
		reference operator*() const {
			Iter cpy(_iterator);
			--cpy;
			return (*cpy);
		}
		pointer operator->() const {
			Iter cpy(_iterator);
			--cpy;
			return (cpy.base());
		}
		reverse_iterator<Iter> &operator+=(difference_type rhs) {
			_iterator -= rhs;
			return *this;
		}
		reverse_iterator<Iter> &operator-=(difference_type rhs) {
			_iterator += rhs;
			return *this;
		}
		reference operator[](difference_type rhs) { return *(_iterator.base() - rhs - 1); }

	private:
		Iter _iterator;
	};
}

namespace ft {
	template <typename T>
	bool operator==(const ft::reverse_iterator<T> &rhs, const ft::reverse_iterator<T> &lhs) { return (lhs.base() == rhs.base()); }
	template <typename U, typename V>
	bool operator==(const ft::reverse_iterator<U> &rhs, const ft::reverse_iterator<V> &lhs) { return (lhs.base() == rhs.base()); }
	template <typename T>
	bool operator!=(const ft::reverse_iterator<T> &rhs, const ft::reverse_iterator<T> &lhs) { return (lhs.base() != rhs.base()); }
	template <typename U, typename V>
	bool operator!=(const ft::reverse_iterator<U> &rhs, const ft::reverse_iterator<V> &lhs) { return (lhs.base() != rhs.base()); }
	template <typename T>
	bool operator>=(const ft::reverse_iterator<T> &rhs, const ft::reverse_iterator<T> &lhs) { return (lhs.base() >= rhs.base()); }
	template <typename U, typename V>
	bool operator>=(const ft::reverse_iterator<U> &rhs, const ft::reverse_iterator<V> &lhs) { return (lhs.base() >= rhs.base()); }
	template <typename T>
	bool operator<=(const ft::reverse_iterator<T> &rhs, const ft::reverse_iterator<T> &lhs) { return (lhs.base() <= rhs.base()); }
	template <typename U, typename V>
	bool operator<=(const ft::reverse_iterator<U> &rhs, const ft::reverse_iterator<V> &lhs) { return (lhs.base() <= rhs.base()); }
	template <typename T>
	bool operator>(const ft::reverse_iterator<T> &rhs, const ft::reverse_iterator<T> &lhs) { return (lhs.base() > rhs.base()); }
	template <typename U, typename V>
	bool operator>(const ft::reverse_iterator<U> &rhs, const ft::reverse_iterator<V> &lhs) { return (lhs.base() > rhs.base()); }
	template <typename T>
	bool operator<(const ft::reverse_iterator<T> &rhs, const ft::reverse_iterator<T> &lhs) { return (lhs.base() < rhs.base()); }
	template <typename U, typename V>
	bool operator<(const ft::reverse_iterator<U> &rhs, const ft::reverse_iterator<V> &lhs) { return (lhs.base() < rhs.base()); }
	template <typename T>
	ft::reverse_iterator<T> operator+(typename ft::reverse_iterator<T>::difference_type rhs, const ft::reverse_iterator<T> &lhs) { return (lhs.base() - rhs); }
	template <typename U, typename V>
	ft::reverse_iterator<U> operator+(typename ft::reverse_iterator<U>::difference_type rhs, const ft::reverse_iterator<V> &lhs) { return (lhs.base() - rhs); }
	template <typename T>
	ft::reverse_iterator<T> operator+(const ft::reverse_iterator<T> &rhs, typename ft::reverse_iterator<T>::difference_type lhs) { return (rhs.base() - lhs); }
	template <typename U, typename V>
	ft::reverse_iterator<U> operator+(const ft::reverse_iterator<U> &rhs, typename ft::reverse_iterator<V>::difference_type lhs) { return (rhs.base() - lhs); }
	template <typename T>
	ft::reverse_iterator<T> operator-(const ft::reverse_iterator<T> &rhs, typename ft::reverse_iterator<T>::difference_type lhs) { return (rhs.base() + lhs); }
	template <typename U, typename V>
	ft::reverse_iterator<U> operator-(const ft::reverse_iterator<U> &rhs, typename ft::reverse_iterator<V>::difference_type lhs) { return (rhs.base() + lhs); }
	template <typename T>
	typename ft::reverse_iterator<T>::difference_type operator-(const ft::reverse_iterator<T> &rhs, const ft::reverse_iterator<T> &lhs) { return (lhs.base() - rhs.base()); }
	template <typename U, typename V>
	typename ft::reverse_iterator<U>::difference_type operator-(const ft::reverse_iterator<V> &rhs, const ft::reverse_iterator<U> &lhs)	{ return (lhs.base() - rhs.base()); }
}
