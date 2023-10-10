#ifndef ITER_H
#define ITER_H

#include <string>
#include <iostream>

template <typename T>
void print(T & str)
{
    std::cout << str << std::endl;
}

template <typename T>
void iter(T tab[], int len, void(print)(T & str))
{
    for (int i = 0; i < len; i++)
        print(tab[i]);
}

#endif