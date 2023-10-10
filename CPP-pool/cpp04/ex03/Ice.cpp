#include "Ice.hpp"

//////////

Ice::Ice(): AMateria("ice")
{
    std::cout << "Ice Default Constructor Called" << std::endl;
}

Ice::Ice(Ice const & a): AMateria("ice")
{
    _xp = a._xp;
    std::cout << "Ice Copy Constructor Called" << std::endl;
}

Ice::~Ice()
{
    std::cout << "Ice Destructor Called" << std::endl;
}

//////////

Ice const & Ice::operator=(Ice const & a)
{
    _xp = a._xp;
    return *this;
}

//////////

AMateria* Ice::clone() const
{
    Ice* clone = new Ice(*this);
    return (clone);
}

void Ice::use(ICharacter & target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
