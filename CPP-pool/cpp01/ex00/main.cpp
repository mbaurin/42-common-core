#include "Zombie.hpp"

int main()
{
     std::cout << "-----------------------"<< std::endl;
    {
        Zombie* robert;
        robert = new Zombie("robert");
        robert->announce();
        delete robert;
    }
    std::cout << "-----------------------"<< std::endl;
    {
        Zombie* noé;
        noé = newZombie("noé");
        noé->announce();
        delete noé;
    }
    {
        std::cout << "-----------------------"<< std::endl;
        randomChump("chloé");
    }
}
