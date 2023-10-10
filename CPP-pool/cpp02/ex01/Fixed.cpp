#include "Fixed.hpp"

///////////////

Fixed::Fixed(void): _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(int const integer)
{
    std::cout << "Int constructor called" << std::endl;
    _rawBits = integer << _fractionnalBits;
}

Fixed::Fixed(float const floatingpoint)
{
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(floatingpoint * (1 << _fractionnalBits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

///////////////

void Fixed::setRawBits(int const raw)
{
    _rawBits = raw;
}

int Fixed::getRawBits(void) const
{
    return _rawBits;
}

int Fixed::toInt(void) const
{
    return (_rawBits >> _fractionnalBits);
}

float Fixed::toFloat(void) const
{
    return ((float)_rawBits / (float)(1 << _fractionnalBits));
}

///////////////

Fixed & Fixed::operator=(Fixed const & src)
{
    std::cout << "Assignation operator called" << std::endl;
    _rawBits = src.getRawBits();
    return *this;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

///////////////

int const Fixed::_fractionnalBits = 8;