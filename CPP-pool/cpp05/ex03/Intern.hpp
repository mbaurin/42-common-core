# ifndef INTERN_H
# define INTERN_H

# include <string>

class Form;

# include "Form.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const & a);
		~Intern();

		Intern & operator=(Intern const & a);

		Form *makeForm(std::string type, std::string target);
};

struct FormType
{
	std::string type;
	Form *(*make)(std::string);
};

#endif