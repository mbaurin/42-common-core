#include "Span.hpp"

int main()
{
    std::cout << "----------" << std::endl;

    Span sp1 = Span(2);

    try
    {
        sp1.addNumber(6);
        sp1.addNumber(3);      
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << sp1;

    std::cout << "----------" << std::endl;

    Span sp2 = Span(5);

    try
	{
		sp2.addAll(0, 4);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

    std::cout << sp2;

    std::cout << "----------" << std::endl;

    Span sp3 = Span(5);

    sp3.addNumber(1);
    sp3.addNumber(5);
    sp3.addNumber(10);
    sp3.addNumber(20);
    sp3.addNumber(40);

	std::cout << "shortest span: " << sp3.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp3.longestSpan() << std::endl;

    std::cout << "----------" << std::endl;

    return 0;
}