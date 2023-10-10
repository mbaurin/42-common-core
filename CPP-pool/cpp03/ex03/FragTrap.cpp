#include "FragTrap.hpp"

///////////////

FragTrap::FragTrap()
{
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "FragTrap created" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    _name = name;
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "FragTrap " << _name << " created" << std::endl;
}

FragTrap::FragTrap(FragTrap const & a)
{
    *this = a;
    std::cout << "FragTrap created by copy constructor" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destroyed" << std::endl;
}

///////////////

FragTrap & FragTrap::operator=(FragTrap const & a)
{
    std::cout << "Assignation operator called" << std::cout;
    this->_name = a._name;
    this->_attackDamage = a._attackDamage;
    this->_energyPoints = a._energyPoints;
    this->_hitPoints = a._hitPoints;
    return *this;
}

///////////////

void    FragTrap::highFivesGuys()
{
    std::cout << "High Five Guys !!!" << std::endl;
}
