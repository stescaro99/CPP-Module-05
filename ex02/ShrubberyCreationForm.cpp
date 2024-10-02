#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137), target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("default", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), target(copy.target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	if (this != &copy)
	{
		this->AForm::operator=(copy);
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream file((this->target + "_shrubbery").c_str());
	if (!file.is_open())
		throw ShrubberyCreationForm::FileNotOpenException();
	file << "      /\\      " << "       " << "      /\\      " <<std::endl;
	file << "     /\\*\\     " << "       " << "     /\\*\\     " <<std::endl;
	file << "    /\\O\\*\\    " << "       " << "    /\\O\\*\\    " <<std::endl;
	file << "   /*/\\/\\/\\   " << "       " << "   /*/\\/\\/\\   " <<std::endl;
	file << "  /\\O\\/\\*\\/\\  " << "       " << "  /\\O\\/\\*\\/\\  " <<std::endl;
	file << " /\\*\\/\\*\\/\\/\\ " << "       " << " /\\*\\/\\*\\/\\/\\ " <<std::endl;
	file << "/\\O\\/\\/*/\\/O/\\" << "       " << "/\\O\\/\\/*/\\/O/\\" <<std::endl;
	file << "      ||      " << "       " << "      ||      " <<std::endl;
	file.close();
}

const char *ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
	return "File could not be opened";
}