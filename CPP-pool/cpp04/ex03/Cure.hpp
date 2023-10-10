#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"

class Cure: public AMateria
{
    public:
        Cure();
        Cure(Cure const & a);
        ~Cure();

        Cure const & operator=(Cure const & a);

        AMateria* clone() const;
        void use(ICharacter & target);

};

#endif