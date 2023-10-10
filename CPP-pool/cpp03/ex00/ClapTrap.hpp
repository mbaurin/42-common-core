#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>
#include <iostream>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const & a);
        ~ClapTrap();

        ClapTrap & operator=(ClapTrap const & a);

        void    setName(std::string name);
        void    setHitPoints(int hitPoints);
        void    setEnergyPoints(int energyPoints);
        void    setAttackDamage(int attackDamage);

        std::string getName();
        int         getHitPoints();
        int         getEnegyPoints();
        int         getAttackDamage();

        void    attack(const std::string & target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

    private:
        std::string _name;
        int         _hitPoints;
        int         _energyPoints;
        int         _attackDamage;
};

#endif