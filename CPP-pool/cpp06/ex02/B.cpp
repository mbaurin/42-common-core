#include "B.hpp"

B::B()
{

}

B::B(B const & B)
{
    (void)(B);
}

B::~B()
{
    
}

B & B::operator=(B const & a)
{
    (void)(a);
    return *this;
}
