#pragma once

namespace ft
{
	template <class T>
	void swap(T &x, T &y) {
		T tmp = x;
		x = y;
		y = tmp;
	}
	template <class Iter1, class Iter2>
	bool equal(Iter1 first1, Iter1 last1, Iter2 first2) {
		while (first1!=last1) {
		if (!(*first1 == *first2))
			return false;
		++first1; ++first2;
		}
		return true;
	}
	template <class Iter1, class Iter2>
	bool lexicographical_compare(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2) {
		while (first1 != last1) {
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			first1++;
			first2++;
		}
		return (first2 != last2);
	}

	template<bool Cond, class T = void> struct enable_if {};
    template<class T> struct enable_if<true, T> { typedef T type; };

	template <bool is_integral, typename T>
	class isIntegralRes
	{
	public:
		typedef T type;
		static const bool value = is_integral;
	};

	template <typename>
	class isIntegralType : public isIntegralRes<false, bool> {};
	template <>
	struct isIntegralType<bool> : public isIntegralRes<true, bool> {};
	template <>
	struct isIntegralType<char> : public isIntegralRes<true, char> {};
	template <>
	struct isIntegralType<signed char> : public isIntegralRes<true, signed char> {};
	template <>
	struct isIntegralType<short int> : public isIntegralRes<true, short int> {};
	template <>
	struct isIntegralType<int> : public isIntegralRes<true, int> {};
	template <>
	struct isIntegralType<long int> : public isIntegralRes<true, long int> {};
	template <>
	struct isIntegralType<long long int> : public isIntegralRes<true, long long int> {};
	template <>
	struct isIntegralType<unsigned char> : public isIntegralRes<true, unsigned char> {};
	template <>
	struct isIntegralType<unsigned short int> : public isIntegralRes<true, unsigned short int> {};
	template <>
	struct isIntegralType<unsigned int> : public isIntegralRes<true, unsigned int> {};
	template <>
	struct isIntegralType<unsigned long int> : public isIntegralRes<true, unsigned long int> {};
	template <>
	struct isIntegralType<unsigned long long int> : public isIntegralRes<true, unsigned long long int> {};
	
	template <typename T>
    class is_integral : public isIntegralType<T> {};

	template <class Arg1, class Arg2, class Result>
	struct compareFct
	{
		typedef Arg1 firstArgument;
		typedef Arg2 secondArgument;
		typedef Result resultType;
	};
	template <class T>
	struct less: compareFct<T, T, bool> { bool operator() (const T& x, const T& y) const { return (x < y); } };
}
