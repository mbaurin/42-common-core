#pragma once

namespace ft
{
	template <typename T, typename V>
	class pair
	{
	public:
		T first;
		V second;

		/*------------------------------- CONSTRUCTOR --------------------------------*/

		pair(): first(), second() {}
		pair(const T &u, const V &v): first(u), second(v) {}
		pair(const pair<T, V> &cpy): first(cpy.first), second(cpy.second) {}
		
		/*------------------------------- DESTRUCTOR --------------------------------*/

		~pair() {}

		/*------------------------------- OPERATORS --------------------------------*/

		pair<T, V> &operator=(const pair<T, V> &rhs) {
			first = rhs.first;
			second = rhs.second;
			return *this;
		}
		friend bool operator==(const pair<T, V> &lhs, const pair<T, V> &rhs) { return (lhs.first == rhs.first && lhs.second == rhs.second); }
		friend bool operator!=(const pair<T, V> &lhs, const pair<T, V> &rhs) { return !(lhs == rhs); }
		friend bool operator<(const pair<T, V> &lhs, const pair<T, V> &rhs) { return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second)); }
		friend bool operator<=(const pair<T, V> &lhs, const pair<T, V> &rhs) { return !(rhs < lhs); }
		friend bool operator>(const pair<T, V> &lhs, const pair<T, V> &rhs) { return (rhs < lhs); }
		friend bool operator>=(const pair<T, V> &lhs, const pair<T, V> &rhs) { return !(lhs < rhs); }
	};

	template <typename T, typename V>
	pair<T, V> make_pair(T u, V v) { return (pair<T, V>(u, v)); }
}
