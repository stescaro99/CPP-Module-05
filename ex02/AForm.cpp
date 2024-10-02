#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, short gradeToSign, short gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	std::cout << "AForm constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy) : name(copy.name), isSigned(copy.isSigned), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &copy)
{
	std::cout << "AForm assignation operator called" << std::endl;
	if (this != &copy)
	{
		this->isSigned = copy.getIsSigned();
	}
	return *this;
}

const std::string AForm::getName() const
{
	return this->name;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

short AForm::getGradeToSign() const
{
	return this->gradeToSign;
}

short AForm::getGradeToExecute() const
{
	return this->gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "Form " << form.getName() << " is ";
	if (form.getIsSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute";
	return out;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->gradeToExecute)
		throw AForm::GradeTooLowException();
}