#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

class Dog: public Animal
{
    public:
        Dog();
        Dog(Dog const & a);
        ~Dog();

        Dog & operator=(Dog const & a);

        void makeSound() const;

};

#endif