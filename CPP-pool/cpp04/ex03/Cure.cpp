#include "Cure.hpp"

//////////

Cure::Cure(): AMateria("cure")
{
    std::cout << "Cure Default Constructor Called" << std::endl;
}

Cure::Cure(Cure const & a): AMateria("cure")
{
    _xp = a._xp;
    std::cout << "Cure Copy Constructor Called" << std::endl;
}

Cure::~Cure()
{
    std::cout << "Cure Destructor Called" << std::endl;
}

//////////

Cure const & Cure::operator=(Cure const & a)
{
    _xp = a._xp;
    return *this;
}

//////////

AMateria* Cure::clone() const
{
    Cure* clone = new Cure(*this);
    return (clone);
}

void Cure::use(ICharacter & target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    AMateria::use(target);
}
