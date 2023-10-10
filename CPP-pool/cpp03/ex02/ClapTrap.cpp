#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    setAttackDamage(0);
    setEnergyPoints(10);
    setHitPoints(10);
    std::cout << "Claptrap created" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    _name = name;
    setAttackDamage(0);
    setEnergyPoints(10);
    setHitPoints(10);
    std::cout << "Claptrap " << _name << " created" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & a)
{
    *this = a;
    std::cout << "Claptrap " << _name << " created by copy constructor" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Claptrap destroyed" << std::endl;
}

///////////////

ClapTrap & ClapTrap::operator=(ClapTrap const & a)
{
    std::cout << "Assignation operator caled" << std::endl;
    this->_name = a._name;
    this->_hitPoints = a._hitPoints;
    this->_energyPoints = a._energyPoints;
    this->_attackDamage = a._attackDamage;
    return *this;
}

///////////////

std::string ClapTrap::getName()
{
    return _name;
}

int ClapTrap::getHitPoints()
{
    return _hitPoints;
}

int ClapTrap::getEnegyPoints()
{
    return _energyPoints;
}

int ClapTrap::getAttackDamage()
{
    return _attackDamage;
}

///////////////

void    ClapTrap::setName(std::string name)
{
    _name = name;
}

void    ClapTrap::setHitPoints(int hitPoints)
{
    _hitPoints = hitPoints;
}

void    ClapTrap::setEnergyPoints(int energyPoints)
{
    _energyPoints = energyPoints;
}

void    ClapTrap::setAttackDamage(int attackDamage)
{
    _attackDamage = attackDamage;
}

///////////////

void    ClapTrap::attack(const std::string & target)
{
    if (_energyPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attack " << target << ", causing " << _attackDamage << " points of damage" << std::endl;
        _energyPoints -= 1;
    }
    else
        std::cout << "ClapTrap " << _name << " n'as plus assez d'énergies" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    _hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " take " << amount << " points of damage and now have " << _hitPoints << " hitPoints" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints > 0)
    {
        _hitPoints += amount;
        _energyPoints -= 1;
        std::cout << "ClapTrap " << _name << " repair itself and get " << amount << " of hit points back. He now have " << _hitPoints << " of hitPoints" << std::endl;
    }
    else
        std::cout << "ClapTrap " << _name << " n'as plus assez d'énergies" << std::endl;
}
