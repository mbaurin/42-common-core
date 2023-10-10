#include "Dog.hpp"

//////////

Dog::Dog(): Animal("Dog")
{
    std::cout << "Default Dog Constructor called" << std::endl;
}

Dog::Dog(Dog const & a)
{
    (Animal(a));
    std::cout << "Copy Dog Constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

//////////

Dog & Dog::operator=(Dog const & a)
{
    Animal::operator=(a);
    return *this;
}

//////////

void Dog::makeSound() const 
{
    std::cout << "Waouf" << std::endl;
}