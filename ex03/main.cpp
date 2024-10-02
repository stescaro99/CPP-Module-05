#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;
	Bureaucrat bureaucrat("bureaucrat", 1);
	AForm *form;

	form = intern.makeForm("shrubbery creation", "target");
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	if (form)
		delete form;

	form = intern.makeForm("robotomy request", "target");
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	if (form)
		delete form;

	form = intern.makeForm("presidential pardon", "target");
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	if (form)
		delete form;

	form = intern.makeForm("unknown form", "target");
	if (form)
		delete form;
	return 0;
}