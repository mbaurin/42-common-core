#include "Fixed.hpp"

///////////////

Fixed::Fixed(): _rawBits(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
    //std::cout << "Copy constructor called" << std::endl;
    this->_rawBits = src.getRawBits();
}

Fixed::Fixed(int const integer)
{
    //std::cout << "Int constructor called" << std::endl;
    _rawBits = integer << _fractionnalBits;
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
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

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    _rawBits = rhs.getRawBits();
    return *this;
}

bool Fixed::operator>(Fixed const & rhs)
{
    return toFloat() > rhs.toFloat();
}

bool Fixed::operator<(Fixed const & rhs)
{
    return toFloat() < rhs.toFloat();
}

bool Fixed::operator>=(Fixed const & rhs)
{
    return toFloat() >= rhs.toFloat();
}

bool Fixed::operator<=(Fixed const & rhs)
{
    return toFloat() <= rhs.toFloat();
}

bool Fixed::operator==(Fixed const & rhs)
{
    return toFloat() == rhs.toFloat();
}

bool Fixed::operator!=(Fixed const & rhs)
{
    return toFloat() != rhs.toFloat();
}

///////////////

Fixed   Fixed::operator+(Fixed const & rhs) const
{
    return toFloat() + rhs.toFloat();
}

Fixed   Fixed::operator-(Fixed const & rhs) const
{
    return toFloat() - rhs.toFloat();
}

Fixed   Fixed::operator*(Fixed const & rhs) const
{
    return toFloat() * rhs.toFloat();
}

Fixed   Fixed::operator/(Fixed const & rhs) const
{
    return toFloat() / rhs.toFloat();
}

///////////////

Fixed & Fixed::operator++(void)
{
    _rawBits++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed	tmp (*this);
	_rawBits++;
	return tmp;
}

Fixed & Fixed::operator--(void)
{
    _rawBits--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed	tmp (*this);
	_rawBits--;
	return tmp;
}

///////////////

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
    if (a > b)
        return a;
    else
        return b;
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
    if (a < b)
        return a;
    else
        return b;
}

///////////////

int const Fixed::_fractionnalBits = 8;