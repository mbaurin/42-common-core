#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap a("rené");
    ScavTrap b("paul");

    std::cout << "----------" << std::endl;
    a.attack("paul");
    b.takeDamage(a.getAttackDamage());
    b.attack("rené");
    a.takeDamage(b.getAttackDamage());
    b.guardGate();
    std::cout << "----------" << std::endl;
}