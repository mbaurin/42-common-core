#ifndef CHARACHTER_H
#define CHARACHTER_H

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter
{
    public:
        Character(std::string const & name);
        Character(Character const & a);
        virtual ~Character();

        Character & operator=(Character const & a);

        std::string const & getName() const;
        
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter & target);

    private:
        Character();
        std::string _name;
        AMateria* _materia[4];
        int _nbMateria;

};

#endif