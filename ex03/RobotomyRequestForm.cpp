#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45), target("default")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("default", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), target(copy.target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	if (this != &copy)
	{
		this->AForm::operator=(copy);
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << "Bzzzzzzzz" << std::endl;
	if (rand() % 2)
		std::cout << this->target << " has been robotomized" << std::endl;
	else
		std::cout << this->target << " robotomization failed" << std::endl;
}