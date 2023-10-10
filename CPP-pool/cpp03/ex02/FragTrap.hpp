#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap const & a);
        ~FragTrap();

        FragTrap & operator=(FragTrap const & a);

        void attack(std::string target);
        void highFivesGuys(void);

    private:
    
};

#endif