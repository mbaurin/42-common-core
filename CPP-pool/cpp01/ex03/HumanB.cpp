#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
    
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
    std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}

void HumanB::setType(Weapon &weapon)
{
    _weapon = &weapon;
}
