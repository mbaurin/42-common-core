#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string name);
        ~HumanB();
        void attack();
        void setType(Weapon &weapon);

    private:
        std::string _name;
        Weapon *_weapon;
};

#endif