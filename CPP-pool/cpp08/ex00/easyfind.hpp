#ifndef EASYFIND_H
#define EASYFIND_H

#include <string>
#include <iostream>
#include <array>

template <typename T>
int & easyfind(T & a, int n)
{
    typename T::iterator iterateur;

    iterateur = std::find(a.begin(), a.end(), n);
    if (iterateur == a.end())
        throw std::exception();
    return *iterateur;
}

#endif