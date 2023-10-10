#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
    public:
        Animal();
        Animal(std::string type);
        Animal(Animal const & a);
        virtual ~Animal();

        Animal & operator=(Animal const & a);

        std::string getType() const;
        virtual void makeSound() const = 0;

    protected:
        std::string _type;

};

#endif