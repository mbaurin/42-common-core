#include "Bureaucrat.hpp"

int main()
{
    std::cout << "----------" << std::endl;

    Bureaucrat a("lucas", 100);
    Bureaucrat b("mathilde", 150);
    Bureaucrat c("eva", 1);

    std::cout << "----------" << std::endl;

    std::cout << a;
    std::cout << b;
    std::cout << c;

    std::cout << "----------" << std::endl;

    try
    {
        a.riseGrade();
        std::cout << a;
        a.downGrade();
        std::cout << a;
        a.downGrade();
        std::cout << a;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "----------" << std::endl;

    try
    {
        b.riseGrade();
        std::cout << b;
    }
    catch (const std::exception &e) 
    {
        std::cerr << e.what() << '\n';
    }

     std::cout << "----------" << std::endl;

    try
    {
        b.downGrade();
        std::cout << b;
        b.downGrade();
        std::cout << b;
    }
    catch (const std::exception &e) 
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "----------" << std::endl;

    return 0;
}
