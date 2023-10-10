#ifndef SHRUBERRYCREATIONFORM_H
#define SHRUBERRYCREATIONFORM_H

#include <string>
#include <iostream>
#include <fstream>

class Form;

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & a);
		~ShrubberyCreationForm();

		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & a);

		virtual void execute(Bureaucrat const & a) const;

	private:
		std::string _target;

};

#endif