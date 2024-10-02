#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *bureaucrat = new Bureaucrat("Tizio", 150);

	std::cout << *bureaucrat;
	
	try
	{
		bureaucrat->incrementGrade();
		std::cout << *bureaucrat;
		bureaucrat->decrementGrade();
		std::cout << *bureaucrat;
		bureaucrat->decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	delete bureaucrat;
	return 0;
}