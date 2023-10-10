#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

#include "Bureaucrat.hpp"

class Form
{
	public:
		Form(std::string name, bool isSigned, int gradeToExec, int gradeToSign);
		Form(Form const & a);
		virtual ~Form();

		Form & operator=(Form const & a);

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExec() const;
		bool getisSigned() const;

		void setisSigned(bool value);
		void setName(std::string name);
		void setGradeToExec(int grade);
		void setGradeToSign(int grade);

		void beSigned(Bureaucrat const & a);
		virtual void execute(Bureaucrat const & executor) const = 0; /* ALERT */

		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class GradeExecTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};

	private:
		Form();
		const std::string _name;
		bool _isSigned;
		const int _gradeToExec;
		const int _gradeToSign;
};

std::ostream & operator<<(std::ostream & ostream, const Form & a);

#endif