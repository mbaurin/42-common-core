#include "Array.hpp"

int main()
{
    Array      <int>array(5);
    Array      <int>array2(10);

    for (int i = 0; i < 5; i++)
        array[i] = i;

    for (int i = 0; i < 10; i++)
        array2[i] = i + 10;

    std::cout << array << " size : " << array.size() << std::endl;
    std::cout << array2 << " size : " << array2.size() << std::endl;

    array = array2;
    
    std::cout << array << " size : " << array.size() << std::endl;

    return 0;
}
