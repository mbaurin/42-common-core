#include "Cat.hpp"

//////////

Cat::Cat(): Animal("Cat")
{
    std::cout << "Default Cat Constructor called" << std::endl;
}

Cat::Cat(Cat const & a)
{
    (Animal(a));
    std::cout << "Copy Cat Constructor called" << std::endl;
}

Cat::~Cat()
{
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