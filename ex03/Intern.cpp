#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called\n";
}

Intern::Intern(Intern const &src)
{
	std::cout << "Intern copy constructor called\n";
	*this = src;
}

Intern::~Intern()
{
	std::cout << "Intern default destructor called\n";
}

Intern &Intern::operator=(Intern const &rhs)
{
	std::cout << "Intern assignation operator called\n";
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	int i = 0;

	std::string lowerFormName;

	for (std::string::size_type i = 0; i < formName.length(); i++)
		lowerFormName += tolower(formName[i]);

	while (i < 3 && formNames[i] != lowerFormName)
		i++;
	switch (i)
	{
		case 0:
			return new ShrubberyCreationForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);
	}
	std::cout << "Intern cannot create " << formName << " because it is an unknown form" << std::endl;
	return NULL;
}