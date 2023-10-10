#include "Form.hpp"

//////////

Form::Form() : _name("Classic Form"), _gradeToExec(150), _gradeToSign(150)
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

void Form::setisSigned(bool value)
{
	_isSigned = value;
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

//////////

const char *Form::GradeTooHighException::what() const throw()
{
    return "Error : Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Error : Grade is too low";
}

const char *Form::GradeExecTooLowException::what() const throw()
{
    return "Error : Grade execution is too low";
}

//////////

std::ostream &operator<<(std::ostream &ostream, const Form &ref)
{
	ostream << "Form " << ref.getName() << " and is ";
	if (ref.getisSigned() == true)
		ostream << "signed";
	else
		ostream << "not signed";
	ostream << ", with a grade to sign = " << ref.getGradeToSign() << " and a grade to exec = " << ref.getGradeToExec() << std::endl;
	return ostream;
}