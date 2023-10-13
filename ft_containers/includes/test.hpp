#ifndef TESTS_HPP
# define TESTS_HPP

# include <iostream>
# include <vector>
# include <map>
# include "vector.hpp"
# include "map.hpp"

void testVector();
void testMap();

template <typename T>
inline void check(std::string name, T a, T b) {
	if (a == b)
		std::cout << name << ": " <<  "✓"  << std::endl;
	else
		std::cout << name << ": " << "⨯" << std::endl;
};

template <typename T>
bool operator==(ft::vector<T> &a, std::vector<T> &b) {
	if (a.size() != b.size())
		return false;
	if (a.empty() != b.empty())
		return false;
	for (size_t i = 0; i < a.size(); i++)
		if (a[i] != b[i])
			return false;
	return true;
};

template <typename T, typename S>
bool operator==(ft::map<T, S> &a, std::map<T, S> &b) {
	if (a.size() != b.size())
		return false;
	if (a.empty() != b.empty())
		return false;
	typename ft::map<T, S>::iterator it = a.begin();
	typename std::map<T, S>::iterator it2 = b.begin();
	while (it != a.end()) {
		if (it->first != it2->first || it->second != it2->second)
			return false;
		++it;
		++it2;
	}
	return true;
};

#endif
