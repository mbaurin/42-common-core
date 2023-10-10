#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"

class Ice: public AMateria
{
    public:
        Ice();
        Ice(Ice const & a);
        ~Ice();

        Ice const & operator=(Ice const & a);

        AMateria* clone() const;
        void use(ICharacter & target);

};

#endif