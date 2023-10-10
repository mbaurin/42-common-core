#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("jean");
    ClapTrap b("claude");
    ClapTrap c("anaïs");

    std::cout << "----------" << std::endl;
    int saveEnergyPoints = a.getEnegyPoints();
    while (a.getEnegyPoints())
        a.attack("claude");
    b.takeDamage(saveEnergyPoints * a.getAttackDamage());
    b.beRepaired(saveEnergyPoints * a.getAttackDamage());
    std::cout << "----------" << std::endl;

    std::cout << "----------" << std::endl;
    c.attack("jean");
    a.takeDamage(c.getAttackDamage());
    a.beRepaired(c.getAttackDamage());
    a.attack("anaïs");
    std::cout << "----------" << std::endl;

}