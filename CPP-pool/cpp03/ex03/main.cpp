#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap a("josé");
    DiamondTrap b("michelle");

    std::cout << "----------" << std::endl;
    a.whoAmI();
    a.ScavTrap::attack("michelle");
    std::cout << "----------" << std::endl;
}
