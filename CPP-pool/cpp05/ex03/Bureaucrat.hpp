#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>
#include <iostream>
#include <exception>

class Form;

#include "Form.hpp"

class Bureaucrat
{
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & a);
		~Bureaucrat();

		Bureaucrat & operator=(Bureaucrat const & a);

		std::string getName() const;
		int getGrade() const;

		void riseGrade();
		void downGrade();
		void signForm(Form const & a) const;
		void executeForm(Form const & a);

		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};

	private:
		Bureaucrat();
		const std::string _name;
		int _grade;

};

std::ostream & operator<<(std::ostream & ostream, const Bureaucrat & a);

#endif