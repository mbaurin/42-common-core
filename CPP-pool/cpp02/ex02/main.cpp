#include "Fixed.hpp"

int main(void)
{
    Fixed a(45);
    Fixed b(10);

    std::cout << "------------------" << std::endl;
    std::cout << "supérieur: ";
    if (a > b)
        std::cout << "a est supérieur" << std::endl;
    else
        std::cout << "b est supérieur" << std::endl;
    std::cout << "inférieur: ";
    if (a < b)
        std::cout << "a est inférieur" << std::endl;
    else
        std::cout << "b est inférieur" << std::endl;
    std::cout << "supérieur ou égale: ";
    if (a >= b)
        std::cout << "a est supérieur ou égale" << std::endl;
    else
        std::cout << "b est supérieur ou égale" << std::endl;
    std::cout << "inférieur ou égale: ";
    if (a <= b)
        std::cout << "a est inférieur ou égale" << std::endl;
    else
        std::cout << "b est inférieur ou égale" << std::endl;
    std::cout << "égale/différent: ";
    if (a == b)
        std::cout << "a et b sont égaux" << std::endl;
    else if (a != b)
        std::cout << "a et b sont differents" << std::endl;
    std::cout << "------------------" << std::endl;

    std::cout << std::endl;
    
    std::cout << "------------------" << std::endl;
    std::cout << "addition: " << a + b << std::endl;
    std::cout << "soustraction: " << a - b << std::endl;;
    std::cout << "multiplication : " << a * b << std::endl;;
    std::cout << "division: " << a / b << std::endl;
    std::cout << "------------------" << std::endl;

    std::cout << std::endl;

    std::cout << "------------------" << std::endl;
    std::cout << "pre-incrementation: " << a << " -> " << ++a << std::endl;
    std::cout << "post-incrementation: " << a << " -> "<< a++ << std::endl;
    std::cout << "pre-decrementation: " << a << " -> " << --a << std::endl;
    std::cout << "post-decrementation: " << a << " -> " << a-- << " -> " << a << std::endl;
    std::cout << "------------------" << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "------------------" << std::endl;
    std::cout << "minimum: " << Fixed::min(a, b) << std::endl;
    std::cout << "maximum: " << Fixed::max(a, b) << std::endl;
    std::cout << "------------------" << std::endl;

    return 0;
}