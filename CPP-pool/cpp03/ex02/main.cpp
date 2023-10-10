#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ScavTrap b("thomas");
    FragTrap c("zoé");

    std::cout << "----------" << std::endl;
    b.attack("zoé");
    c.takeDamage(b.getAttackDamage());
    c.beRepaired(b.getAttackDamage());
    c.attack("thomas");
    b.takeDamage(c.getAttackDamage());
    c.highFivesGuys();
    std::cout << "----------" << std::endl;

}