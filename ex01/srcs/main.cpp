#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

	Bureaucrat nonExistant;
	Bureaucrat Fred("Fredo", 3);
	std::cout << nonExistant << std::endl;
	try {
		Form contract("ambulancier", 20, 60);
		Bureaucrat johnson("Johnson", 65);
		std::cout << contract << std::endl;
		std::cout << johnson << std::endl << std::endl;
		johnson.signForm(contract);
		johnson.gradeUp();
		johnson.gradeUp();
		johnson.gradeUp();
		johnson.gradeUp();
		johnson.gradeUp();
		johnson.gradeUp();
		johnson.signForm(contract);
		Fred.gradeUp();
		Fred.gradeUp();
		Fred.gradeUp();
		std::cout << std::endl << std::endl << contract << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
		Bureaucrat fredTwin(Fred);
		std::cout << fredTwin << std::endl;
	}

}
