#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

//////////

Intern::Intern()
{
	std::cout << "Intern has been created" << std::endl;
}

Intern::Intern(Intern const & a) 
{
	(void)(a);
	std::cout << "Intern has been created" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern has been destroyed" << std::endl;
}

//////////

Intern & Intern::operator=(Intern const & a)
{
	(void)(a);
	return *this;
}

//////////

Form *makeShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

Form *makeRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

Form *makePardon(std::string target)
{
	return new PresidentialPardonForm(target);
}

Form *Intern::makeForm(std::string type, std::string target)
{
	static struct FormType types[3] = {
		{ "shrubbery creation", makeShrubbery },
		{ "robotomy request", makeRobotomy },
		{ "presidential pardon", makePardon }
	};

	for (int i = 0; i < 3; i++)
	{
		if (types[i].type == type)
		{
			std::cout << "Intern creates " << type << std::endl;
			return types[i].make(target);
		}
	}

	std::cout << "Unknown form type: " << type << std::endl;
	
	return NULL;
}
