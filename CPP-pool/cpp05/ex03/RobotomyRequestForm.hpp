#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <string>
#include <iostream>

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & a);
		~RobotomyRequestForm();

		RobotomyRequestForm & operator=(RobotomyRequestForm const & a);

		virtual void execute(Bureaucrat const & a) const;

	private:
		std::string _target;
};

#endif
