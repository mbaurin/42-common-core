#ifndef AMATERIA_H
#define AMATERIA_H

#include <string>
#include <iostream>

class AMateria;

#include "ICharacter.hpp"

class AMateria
{   
    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(AMateria const & a);
        virtual ~AMateria();

        AMateria & operator=(AMateria const & a);

        std::string const & getType() const;
        unsigned int getXp() const;

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter & target);

    protected:
        std::string _type;
        unsigned int _xp;

};

#endif