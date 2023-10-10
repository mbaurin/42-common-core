#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "----------" << std::endl;

    Bureaucrat a("arthur", 1);
    Bureaucrat b("louise", 150);
	ShrubberyCreationForm maison("maison");
	RobotomyRequestForm robot("robot");
	PresidentialPardonForm president("micron");

	std::cout << "----------" << std::endl;

    std::cout << a;
    std::cout << b;
	std::cout << maison;
	std::cout << robot; 
	std::cout << president; 

	std::cout << "----------" << std::endl;

	try
	{
		a.executeForm(robot);
		b.executeForm(maison);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "----------" << std::endl;

	try
	{
		maison.execute(a);
		maison.execute(b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "----------" << std::endl;

	try
	{
		robot.execute(a);
		robot.execute(b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "----------" << std::endl;

	try
	{
		president.execute(a);
		president.execute(b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "----------" << std::endl;

	return 0;

}
