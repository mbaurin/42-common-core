#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

class Weapon
{
    public:
        Weapon(std::string type);
        ~Weapon();
        void setType(std::string type);
        const std::string &getType() const;
    private:
        std::string _type;
};

#endif