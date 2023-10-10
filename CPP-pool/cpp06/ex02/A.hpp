#ifndef A_H
#define A_H

#include "Base.hpp"

class A: public Base
{
    public:
        A();
        A(A const & a);
        virtual ~A();

        A & operator=(A const & a);
};

#endif
