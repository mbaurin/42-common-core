#ifndef C_H
#define C_H

#include "Base.hpp"

class C: public Base
{
    public:
        C();
        C(C const & a);
        virtual ~C();

        C & operator=(C const & a);
};

#endif