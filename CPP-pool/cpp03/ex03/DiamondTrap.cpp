#include "DiamondTrap.hpp"

///////////////

DiamondTrap::DiamondTrap()
{
    setName("none");
    ClapTrap::setName(getName() + "_clap_name");
    setHitPoints(FragTrap::getHitPoints());
    setEnergyPoints(ScavTrap::getEnegyPoints());
    setAttackDamage(FragTrap::getAttackDamage());
    std::cout << "Default DiamondTrap created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
    _name = name;
    ClapTrap::setName(getName() + "_clap_name");
    setHitPoints(FragTrap::getHitPoints());
    setEnergyPoints(ScavTrap::getEnegyPoints());
    setAttackDamage(FragTrap::getAttackDamage());
    std::cout << "DiamondTrap " << _name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & a)
{
    *this = a;
    std::cout << "Diamond " << _name << " created by copy constructos" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Diamondtrap " << _name << " destroyed" << std::endl;
}

///////////////

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & a)
{
    std::cout << "Assignation operator called";
    this->_name = a._name;
    this->_attackDamage = a._attackDamage;
    this->_energyPoints = a._energyPoints;
    this->_hitPoints = a._energyPoints;
    return *this;
}

///////////////

void    DiamondTrap::setName(std::string name)
{
    _name = name;
}

std::string DiamondTrap::getName()
{
    return _name;
}

///////////////

void    DiamondTrap::whoAmI()
{
    std::cout << "Hi my DiamondTrap name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl; 
}

///////////////

