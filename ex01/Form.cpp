#include "Bureaucrat.hpp"

Form::Form() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &name, short gradeToSign, short gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	std::cout << "Form constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : name(copy.name), isSigned(copy.isSigned), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(const Form &copy)
{
	std::cout << "Form assignation operator called" << std::endl;
	if (this != &copy)
	{
		this->isSigned = copy.getIsSigned();
	}
	return *this;
}

const std::string Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

short Form::getGradeToSign() const
{
	return this->gradeToSign;
}

short Form::getGradeToExecute() const
{
	return this->gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName() << " is ";
	if (form.getIsSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires a grade " << form.getGradeToSign() << " to sign and a grade " << form.getGradeToExecute() << " to execute";
	return out;
}
