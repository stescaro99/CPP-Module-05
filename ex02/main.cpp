#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat bureaucrat("bureaucrat", 1);
	ShrubberyCreationForm shrubberyCreationForm("shrubbery");
	RobotomyRequestForm robotomyRequestForm("robotomy");
	PresidentialPardonForm presidentialPardonForm("presidential");

	std::cout << bureaucrat << std::endl;
	std::cout << shrubberyCreationForm << std::endl;
	std::cout << robotomyRequestForm << std::endl;
	std::cout << presidentialPardonForm << std::endl;

	bureaucrat.signForm(shrubberyCreationForm);
	bureaucrat.signForm(robotomyRequestForm);
	bureaucrat.signForm(presidentialPardonForm);

	bureaucrat.executeForm(shrubberyCreationForm);
	bureaucrat.executeForm(robotomyRequestForm);
	bureaucrat.executeForm(presidentialPardonForm);

	return 0;
}