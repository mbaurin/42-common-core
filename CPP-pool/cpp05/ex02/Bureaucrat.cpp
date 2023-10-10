#include "Bureaucrat.hpp"
#include "Form.hpp"

//////////

Bureaucrat::Bureaucrat()
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else
    {
        _grade = grade;
        std::cout << "Bureaucrat " << name << " with grade " << grade << " has been created" << std::endl; 
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const & a) : _name(a._name)
{
    _grade = a._grade;
    std::cout << "Bureaucrat " << _name << " with grade " << _grade << " has been created" << std::endl; 
}

Bureaucrat::~Bureaucrat()
{
     std::cout << "Bureaucrat " << _name << " with grade " << _grade << " has been destroyed" << std::endl; 
}

//////////

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & a)
{
    _grade = a._grade;
    return *this;
}

//////////

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const 
{
    return _grade;
}

//////////

void Bureaucrat::riseGrade()
{
    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    else    
        _grade--;
}

void Bureaucrat::downGrade()
{
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade++;
}

void Bureaucrat::signForm(Form const & a) const
{
	if (a.getGradeToSign() < getGrade())
		std::cout << _name << " can not sign " << a.getName() << " because his grade is too low" << std::endl;
	else
		std::cout << _name << " signs " << a.getName() << std::endl;
	
}

void Bureaucrat::executeForm(Form const & a)
{
	if (a.getGradeToExec() < getGrade())
		throw GradeTooLowException();
	std::cout << getName() << " executs " << a.getName() << std::endl;
}

//////////

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Error : Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Error : Grade is too low";
}

//////////

std::ostream & operator<<(std::ostream & ostream, const Bureaucrat & a)
{
    ostream << a.getName() << ", bureaucrat grade " << a.getGrade() << std::endl;
    return ostream;
}
