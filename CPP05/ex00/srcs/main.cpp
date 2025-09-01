#include "Bureaucrat.hpp"

int main() {


	try 
	{
		Bureaucrat johnson("Johnson", 3);
		std::cout << johnson << std::endl;
		johnson.gradeUp();
		johnson.gradeUp();
		Bureaucrat fried("Friedreich", 189);
		johnson.gradeUp();
		johnson.gradeUp();
		johnson.gradeUp();
		johnson.gradeUp();
		johnson.gradeUp();
	}
	catch (std::exception& e)
	{
		std::cout << "exeption caught: " << e.what() << std::endl;
	}
			

}
