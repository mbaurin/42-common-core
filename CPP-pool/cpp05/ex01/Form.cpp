#include "Form.hpp"

//////////

Form::Form() : _name("Default Form"), _gradeToExec(150), _gradeToSign(150)
{
	std::cout << "Form " << _name << " has been created" << std::endl;
}

Form::Form(std::string name, bool isSigned, int gradeToExec, int gradeToSign) : _name(name), _gradeToExec(gradeToExec), _gradeToSign(gradeToSign)
{
	if (gradeToExec > 150 || gradeToSign > 150)
        throw Form::GradeTooLowException();
    else if (gradeToExec < 1 || gradeToExec < 1)
        throw Form::GradeTooHighException();
	else
	{
		_isSigned = isSigned;
		std::cout << "Form " << _name << " has been created" << std::endl;
	}
}

Form::Form(Form const & a) : _name(a._name), _gradeToExec(a._gradeToExec), _gradeToSign(a._gradeToSign)
{
	_isSigned = a._isSigned;
	std::cout << "Form " << _name << " has been created" << std::endl;
}

Form::~Form()
{
	std::cout << "Form " << _name << " has been destroyed" << std::endl;
}

//////////

Form & Form::operator=(Form const & a)
{
	_isSigned = a._isSigned;
	return *this;
}

//////////

std::string Form::getName() const 
{
	return _name;
}

bool Form::getisSigned() const
{
	return _isSigned;
}

int Form::getGradeToExec() const
{
	return _gradeToExec; 
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

//////////

void Form::beSigned(Bureaucrat const & a)
{
	if (a.getGrade() > this->getGradeToSign())
	{
		a.signForm(*this);
		throw Bureaucrat::GradeTooLowException();
	}
	else
	{
		a.signForm(*this);
		_isSigned = true;
	}
}

void Form::setisSigned(bool value)
{
	_isSigned = value;
}

//////////

const char *Form::GradeTooHighException::what() const throw()
{
    return "Error : Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Error : Grade is too low";
}

//////////

std::ostream & operator<<(std::ostream & ostream, const Form & a)
{
	ostream << "Form " << a.getName() << " is ";
	ostream << (a.getisSigned() ? "signed" : "not signed");
	ostream << ", with a grade to sign = " << a.getGradeToSign() << " and a grade to exec = " << a.getGradeToExec() << std::endl;
	return ostream;
}
