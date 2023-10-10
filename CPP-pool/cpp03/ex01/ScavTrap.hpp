#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const & a);
        ~ScavTrap();

        ScavTrap & operator=(ScavTrap const & a);

        void attack(std::string target);
        void guardGate();

    private:

};

#endif