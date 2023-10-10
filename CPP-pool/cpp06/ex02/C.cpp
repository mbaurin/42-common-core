#include "C.hpp"

C::C()
{

}

C::C(C const & a)
{
    (void)(a);
}

C::~C()
{
    
}

C & C::operator=(C const & a)
{
    (void)(a);
    return *this;
}
