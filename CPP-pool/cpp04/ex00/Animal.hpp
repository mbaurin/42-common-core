#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal
{
    public:
        Animal();
        Animal(std::string type);
        Animal(Animal const & a);
        virtual ~Animal();

        Animal & operator=(Animal const & a);

        std::string getType() const;
        virtual void makeSound() const;

    protected:
        std::string _type;

};

#endif