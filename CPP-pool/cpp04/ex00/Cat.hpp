#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(Cat const & a);
        ~Cat();

        Cat & operator=(Cat const & a);

        void makeSound() const;

};

#endif