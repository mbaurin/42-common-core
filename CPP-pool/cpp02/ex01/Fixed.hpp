#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string>
#include <tgmath.h>

class Fixed
{
    public:
        Fixed();
        Fixed(Fixed const & src);
        Fixed(int const integer);
        Fixed(float const floatingpoint);
        ~Fixed();

        Fixed & operator=(Fixed const & rhs);
        void    setRawBits(int const raw);
        int     getRawBits(void) const;
        float   toFloat(void) const;
        int     toInt(void) const;

    private:
        int                 _rawBits;
        static int const    _fractionnalBits;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif