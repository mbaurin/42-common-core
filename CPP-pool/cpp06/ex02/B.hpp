#ifndef B_H
#define B_H

#include "Base.hpp"

class B: public Base
{
    public:
        B();
        B(B const & a);
        virtual ~B();

        B & operator=(B const & a);
};

#endif