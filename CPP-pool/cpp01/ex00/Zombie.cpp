#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie()
{
    std::cout << "<" << _name << ">" << " died" << std::endl;
}

void Zombie::announce()
{
    std::cout << "<" << _name << ">" << " BraiiiiiiinnnzzzZ..." << std::endl;
}
