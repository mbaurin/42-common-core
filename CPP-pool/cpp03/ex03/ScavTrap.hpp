#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const & a);
        ~ScavTrap();

        ScavTrap & operator=(ScavTrap const & a);

        void attack(std::string target);
        void guardGate();

    private:

};

#endif