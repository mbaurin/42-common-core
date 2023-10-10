#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>
#include <string>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(WrongAnimal const & a);
        ~WrongAnimal();

        WrongAnimal & operator=(WrongAnimal const & a);

        std::string getType();
        void    makeSound() const;

    protected:
        std::string _type;
};

#endif