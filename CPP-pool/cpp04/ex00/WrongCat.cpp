#include "WrongCat.hpp"

//////////

WrongCat::WrongCat()
{
    WrongAnimal("Cat");
}

WrongCat::WrongCat(WrongCat const & a)
{
    (WrongAnimal(a));
}

WrongCat::~WrongCat()
{

}

//////////

WrongCat & WrongCat::operator=(WrongCat const & a)
{
    WrongAnimal::operator=(a);
    return *this;
}

//////////

void WrongCat::makeSound()
{
    std::cout << "Miaou" << std::endl;
}