#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Form form("Mafia", 50, 25);
		std::cout << form << std::endl;
		Bureaucrat terun("Al", 75);
		std::cout << terun << std::endl;
		terun.incrementGrade();
		std::cout << terun << std::endl;
		terun.decrementGrade();
		std::cout << terun << std::endl;
		terun.signForm(form);
		Bureaucrat fussy("John", 150);
		std::cout << fussy << std::endl;
		fussy.signForm(form);
		Bureaucrat shorter("Jack", 30);
		std::cout << shorter << std::endl;
		shorter.signForm(form);
		
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}