#include "Dog.hpp"

//////////

Dog::Dog(): Animal("Dog")
{
    _brain = new Brain();
    std::cout << "Default Dog Constructor called" << std::endl;
}

Dog::Dog(Dog const & a)
{
    (Animal(a));
    _brain = new Brain();
    *_brain = *a._brain;
    std::cout << "Copy Dog Constructor called" << std::endl;
}

Dog::~Dog()
{
    delete _brain;
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

Brain* Dog::getBrain()
{
    return _brain;
}