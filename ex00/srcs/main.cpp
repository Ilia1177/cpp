#include "Bureaucrat.hpp"

int main()
{
	try 
	{
		Bureaucrat johnson("Johnson", 3);
		std::cout << johnson << std::endl;
		johnson.gradeUp();
		johnson.gradeUp();
		std::cout << johnson << std::endl;
		Bureaucrat fried("Friedreich", 147);
		fried.gradeDown();
		std::cout << fried << std::endl;
		fried.gradeDown();
		std::cout << fried << std::endl;
		fried.gradeDown();
		std::cout << fried << std::endl;
		fried.gradeDown();
		std::cout << fried << std::endl;
		johnson.gradeUp();
		johnson.gradeUp();
		johnson.gradeUp();
		johnson.gradeUp();
		std::cout << "no exception caught" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "exeption caught: " << e.what() << std::endl;
	}
	return (0);
}
