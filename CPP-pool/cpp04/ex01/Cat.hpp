#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(Cat const & a);
        virtual ~Cat();

        Cat & operator=(Cat const & a);

        void makeSound() const;

    private:
        Brain*  _brain;
};

#endif