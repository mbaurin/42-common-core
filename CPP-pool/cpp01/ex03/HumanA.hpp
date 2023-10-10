#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void attack();
        void setType(std::string type);

    private:
        std::string _name;
        Weapon &_weapon;
};

#endif