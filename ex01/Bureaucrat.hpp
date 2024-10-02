#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"

class Bureaucrat
{
	private:
		const std::string name;
		short grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, short grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &copy);

		const std::string getName() const;
		short getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(class Form &form);

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
		
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif