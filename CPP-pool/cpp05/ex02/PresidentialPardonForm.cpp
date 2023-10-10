#include "PresidentialPardonForm.hpp"

//////////

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", false, 5, 25)
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", false, 5, 25)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & a) : Form(a.getName(), a.getisSigned(), a.getGradeToExec(), a.getGradeToSign())
{
	_target = a._target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

//////////

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & a)
{
	setisSigned(a.getisSigned());
	_target = a._target;
	return *this;
}

//////////

void PresidentialPardonForm::execute(Bureaucrat const & a) const
{
	if (a.getGrade() > getGradeToExec())
		throw GradeExecTooLowException();
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
