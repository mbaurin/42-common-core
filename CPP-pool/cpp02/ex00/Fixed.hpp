#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string>

class Fixed
{
    public:
        Fixed();
        Fixed(Fixed const & src);
        ~Fixed();

        Fixed & operator=(Fixed const & rhs);
        void    setRawBits(int const raw);
        int     getRawBits(void) const;

    private:
        int                 _rawBits;
        static int const    _fractionnalBits;
};

#endif