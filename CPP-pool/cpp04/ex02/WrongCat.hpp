#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(WrongCat const & a);
        ~WrongCat();

        WrongCat & operator=(WrongCat const & a);

        void makeSound();
};

#endif
