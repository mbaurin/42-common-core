#include "WrongAnimal.hpp"

//////////

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
    _type = type;
    std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & a)
{
    _type = a._type;
    std::cout << "WrongAnimal Copy Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Desctructor called" << std::endl;
}

//////////

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & a)
{
    if (&a == this)
        return *this;
    _type = a._type;
    return *this;
}

//////////

std::string WrongAnimal::getType()
{
    return _type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "*WrongAnimal noise*" << std::endl;
}
