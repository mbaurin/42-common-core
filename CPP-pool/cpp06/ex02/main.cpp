#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <string>
#include <ctime>

Base *generate()
{
    int i;

    i = rand() % 3;
    if (i == 0)
        return (new A);
    else if (i == 1)
        return (new B);
    else
        return (new C);
}

void idByPtr(Base *ptr)
{
    if (A *a = dynamic_cast<A*>(ptr))
        std::cout << "A" << std::endl;
    else if (B *b = dynamic_cast<B*>(ptr))
        std::cout << "B" << std::endl;
    else if (C *c = dynamic_cast<C*>(ptr))
        std::cout << "C" << std::endl;
}

void idByRef(Base &ptr)
{
    try
    {
        A &a = dynamic_cast<A&>(ptr);
        (void)(a);
        std::cout << "A" << std::endl;
    }
    catch(std::exception&) {}

    try
    {
        B &b = dynamic_cast<B&>(ptr);
        (void)(b);
        std::cout << "B" << std::endl;
    }
    catch(std::exception&) {}

    try
    {
        C &c = dynamic_cast<C&>(ptr);
        (void)(c);
        std::cout << "C" << std::endl;
    }
    catch(std::exception&) {}
    
}

int main()
{
    Base *ptr;
    
    srand(std::time(0));
    ptr = generate();
    idByPtr(ptr);
    std::cout << "-" << std::endl;
    idByRef(*ptr);
}
