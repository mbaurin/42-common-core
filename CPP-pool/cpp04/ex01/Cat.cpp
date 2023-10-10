#include "Cat.hpp"

//////////

Cat::Cat(): Animal("Cat")
{
    _brain = new Brain();
    std::cout << "Default Cat Constructor called" << std::endl;
}

Cat::Cat(Cat const & a)
{
    (Animal(a));
    _brain = new Brain();
    *_brain = *a._brain;
    std::cout << "Copy Cat Constructor called" << std::endl;
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "Cat Destructor called" << std::endl;
}

//////////

Cat & Cat::operator=(Cat const & a)
{
    Animal::operator=(a);
    return *this;
}

//////////

void Cat::makeSound() const
{
    std::cout << "Miaou" << std::endl;
}