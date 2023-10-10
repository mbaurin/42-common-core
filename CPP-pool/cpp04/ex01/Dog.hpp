#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

class Dog: public Animal
{
    public:
        Dog();
        Dog(Dog const & a);
        virtual ~Dog();

        Dog & operator=(Dog const & a);

        void makeSound() const;
        Brain* getBrain();

    private:
        Brain*  _brain;
};

#endif