#include "A.hpp"

A::A()
{

}

A::A(A const & a)
{
    (void)(a);
}

A::~A()
{
    
}

A & A::operator=(A const & a)
{
    (void)(a);
    return *this;
}
