#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "----------" << std::endl;

    Bureaucrat a("enzo", 1);
    Bureaucrat b("camille", 150);

	ShrubberyCreationForm maison("Maison");
	RobotomyRequestForm robot("Robot");
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

	Intern  internA;
    Form	*formA;

	std::cout << "----------" << std::endl;

    formA = internA.makeForm("robotomy request", "Bender");

	delete formA;

	std::cout << "----------" << std::endl;
	
	return 0;
}
