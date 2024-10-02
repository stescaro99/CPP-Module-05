#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const short gradeToSign;
		const short gradeToExecute;

	public:
		Form();
		Form(const std::string &name, short gradeToSign, short gradeToExecute);
		Form(const Form &copy);
		~Form();
		Form &operator=(const Form &copy);

		const std::string getName() const;
		bool getIsSigned() const;
		short getGradeToSign() const;
		short getGradeToExecute() const;
		void beSigned(const Bureaucrat &bureaucrat);


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
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif