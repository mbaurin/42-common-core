#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap const & a);
        ~DiamondTrap();

        DiamondTrap & operator=(DiamondTrap const & a);

        void        setName(std::string name);
        std::string getName();

        void    whoAmI();

    private:
        std::string _name;

};

#endif