#include "ShrubberyCreationForm.hpp"

//////////

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreation", false, 137, 145)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreation", false, 137, 145)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & a) : Form(a.getName(), a.getisSigned(), a.getGradeToExec(), a.getGradeToSign())
{

}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{

}

//////////

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & a)
{
	setisSigned(a.getisSigned());
	_target = a._target;
	return *this;
}

//////////

void ShrubberyCreationForm::execute(Bureaucrat const & a) const
{
	if (a.getGrade() > getGradeToExec())
		throw GradeExecTooLowException();
	std::ofstream outfile(_target + "_shrubbery");
	std::ifstream file;

	file.open("assets/tree.txt");
	if (file.is_open())
	{
		std::string tmp((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
		outfile << tmp << std::endl;
		file.close();
		std::cout << "File " << _target << "_shrubbery has been created" << std::endl;
	}
	outfile.close();
}
