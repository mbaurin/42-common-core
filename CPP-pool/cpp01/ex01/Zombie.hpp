#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie
{
public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void announce();
    void set_name(std::string name);

private:
    std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif