#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <fstream>

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const short gradeToSign;
		const short gradeToExecute;

	public:
		AForm();
		AForm(const std::string &name, short gradeToSign, short gradeToExecute);
		AForm(const AForm &copy);
		virtual ~AForm();
		AForm &operator=(const AForm &copy);

		const std::string getName() const;
		bool getIsSigned() const;
		short getGradeToSign() const;
		short getGradeToExecute() const;
		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;


		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif