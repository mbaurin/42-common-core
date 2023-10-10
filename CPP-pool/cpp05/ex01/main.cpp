#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "----------" << std::endl;
    
	Bureaucrat a("henry", 150);
    Bureaucrat b("robert", 1);
	Form form("RSA", false, 100, 1);

	std::cout << "----------" << std::endl;

    std::cout << a;
    std::cout << b;
	std::cout << form;

	std::cout << "----------" << std::endl;

	try
	{
		form.beSigned(a);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "----------" << std::endl;

	std::cout << form;

	std::cout << "----------" << std::endl;

	form.beSigned(b);
	std::cout << form;

	std::cout << "----------" << std::endl;
	
	return 0;
}