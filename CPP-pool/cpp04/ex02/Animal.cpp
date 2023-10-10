#include "Animal.hpp"

//////////

Animal::Animal()
{
    _type = "Animal Classique";
    std::cout << "Default Animal Constructor called" << std::endl;
}

Animal::Animal(std::string type)
{
    _type = type;
    std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(Animal const & a)
{
    _type = a._type;
    std::cout << "Copy Animal Constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

//////////

Animal & Animal::operator=(Animal const & a)
{
    if (&a == this)
        return *this;
    _type = a._type;
    return *this;
}

//////////

std::string Animal::getType() const
{
    return _type;
}

void Animal::makeSound() const
{
    std::cout << "" << std::endl;
}
