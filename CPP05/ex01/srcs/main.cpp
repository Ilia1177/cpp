#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

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
	std::cout << std::endl << std::endl << contract << std::endl;

}
