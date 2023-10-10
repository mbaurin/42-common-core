#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include <iostream>
#include <string>

class Form;

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & a);
		~PresidentialPardonForm();

		PresidentialPardonForm & operator=(PresidentialPardonForm const & a);

		virtual void execute(Bureaucrat const & a) const;

	private:
		std::string _target;
};

#endif