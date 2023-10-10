#include "Zombie.hpp"

Zombie* newZombie( std::string _name )
{
    Zombie *zomb = new Zombie(_name);
    return (zomb);
}
