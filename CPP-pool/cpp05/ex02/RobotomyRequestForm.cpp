#include "RobotomyRequestForm.hpp"

//////////

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", false, 45, 72)
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", false, 45, 72)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & a) : Form(a.getName(), a.getisSigned(), a.getGradeToExec(), a.getGradeToSign())
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

//////////

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & a)
{
	setisSigned(a.getisSigned());
	_target = a._target;
	return *this;
}

//////////

void RobotomyRequestForm::execute(Bureaucrat const & a) const
{
	if (a.getGrade() > getGradeToExec())
		throw GradeExecTooLowException();

    srand (time(NULL));
    if (rand() % 2)
        std::cout << "BZZZZZZZZZZ..." << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "The " << _target << "robotomization failed" << std::endl;
}
