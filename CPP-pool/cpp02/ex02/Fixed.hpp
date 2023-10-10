#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed(Fixed const & src);
        Fixed(int const integer);
        ~Fixed();

        void    setRawBits(int const raw);
        int     getRawBits(void) const;
        float   toFloat(void) const;
        int     toInt(void) const;

        Fixed & operator=(Fixed const & rhs);
        bool operator>(Fixed const & rhs);
        bool operator<(Fixed const & rhs);
        bool operator>=(Fixed const & rhs);
        bool operator<=(Fixed const & rhs);
        bool operator==(Fixed const & rhs);
        bool operator!=(Fixed const & rhs);

        Fixed   operator+(Fixed const & rhs) const;
        Fixed   operator-(Fixed const & rhs) const;
        Fixed   operator*(Fixed const & rhs) const;
        Fixed   operator/(Fixed const & rhs) const;

        Fixed & operator++(void);
        Fixed operator++(int);
        Fixed & operator--(void);
        Fixed operator--(int);

        static Fixed & max(Fixed & a, Fixed & b);
        static Fixed & min(Fixed & a, Fixed & b);

    private:
        int                 _rawBits;
        static int const    _fractionnalBits;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif