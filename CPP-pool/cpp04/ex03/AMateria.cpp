#include "AMateria.hpp"

//////////

AMateria::AMateria()
{
    _type = "Classic AMateria";
    _xp = 0;
    std::cout << "AMateria Default Constructor Called" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
    _type = type;
    _xp = 0;
    std::cout << "AMateria " << _type << " Constructor Called" << std::endl;
}

AMateria::AMateria(AMateria const & a)
{
    _type = a._type;
    _xp = a._xp;
    std::cout << "AMateria Copy Constructor Called" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "AMateria " << _type << " Destructor Called" << std::endl;
}

//////////

AMateria & AMateria::operator=(AMateria const & a)
{
    _type = a._type;
    _xp = a._xp;
    return *this;
}

//////////

std::string const & AMateria::getType() const
{
    return _type;
}

unsigned int AMateria::getXp() const
{
    return _xp;
}

//////////

void AMateria::use(ICharacter & target)
{
    (void)(target);
    _xp += 10;
}
