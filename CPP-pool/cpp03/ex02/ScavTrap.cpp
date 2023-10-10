#include "ScavTrap.hpp"

///////////////

ScavTrap::ScavTrap()
{
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    _name = name;
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "ScavTrap " << _name << " created" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & a)
{
    *this = a;
    std::cout << "Scavtrap created by copy constructor" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Scavtrap destroyed" << std::endl;
}

///////////////

ScavTrap & ScavTrap::operator=(ScavTrap const & a)
{
    std::cout << "Assignation operator caled" << std::endl;
    this->_name = a._name;
    this->_attackDamage = a._attackDamage;
    this->_energyPoints = a._energyPoints;
    this->_hitPoints = a._hitPoints;
    return *this;
}

///////////////

void    ScavTrap::attack(std::string target)
{
    std::cout << "Scavtrap " << _name << " attack " << target << " causing " << _attackDamage << " points of damage" << std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}
