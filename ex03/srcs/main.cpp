#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

// Intern makeform tests
void Intern_tests(Bureaucrat& johnson) {
	std::cout << std::endl << "---- Subject Test" << std::endl << "What do you want ? "; 
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
	}
	
	Intern		marc;
	AForm		*newForm = nullptr;
	std::string	demand;
	std::string	supposedGrade;
	std::string	target = "Undefined";

	std::cout << std::endl << "---- INTERN TESTS" << std::endl << "What do you want ? "; 
	while (std::getline(std::cin, demand)) {
		try {
			std::cout  << std::endl << "What's the target ? ";
			if (!std::getline(std::cin, target))
				break ;
			newForm = marc.makeForm(demand, target);
			std::cout << std::endl << "You asked for: " << std::endl << *newForm;
			std::cout  << std::endl << "What's your grade ? ";
			std::getline(std::cin, supposedGrade);
			int grade = std::stoi(supposedGrade);
			if (johnson.getGrade() > grade)
				for (; johnson.getGrade() != grade; johnson.gradeUp());
			else
				for (; johnson.getGrade() != grade; johnson.gradeDown());
			johnson.signForm(*newForm);
			johnson.executeForm(*newForm);
		}
		catch (std::exception& e) {
			std::cout << "Exception caught in main office:" << std::endl;
			std::cout << "Sorry " << johnson << ", it isn't possible because: " << e.what() << std::endl;
			std::cin.clear();
		}
		delete newForm;
		newForm = nullptr;
		std::cout << "You want an other one ? ";
	}
}

// Presidential forms tests
void Presidential_tests(Bureaucrat& johnson) {
	PresidentialPardonForm excuses("Pardon me");
	std::cout << std::endl << "---- PRESIDENTIAL TESTS" << std::endl;
	std::cout << excuses << std::endl;
	std::cout << johnson << std::endl << std::endl;
	johnson.executeForm(excuses);
	johnson.signForm(excuses);
	for (; johnson.getGrade() > excuses.getSignGrade(); johnson.gradeUp());
	johnson.signForm(excuses);
	for (; johnson.getGrade() > excuses.getExecGrade(); johnson.gradeUp());
	johnson.executeForm(excuses);
	std::cout << std::endl << excuses << std::endl;
}

// Robotomy forms tests
void Robotomy_tests(Bureaucrat& johnson) {
	std::srand(std::time(0)); 
	RobotomyRequestForm robotisation("R2D2");
	std::cout << std::endl << "---- ROBOTOMY TESTS" << std::endl;
	std::cout << robotisation << std::endl;
	for (; johnson.getGrade() != 150; johnson.gradeDown());
	johnson.signForm(robotisation);
	for (; johnson.getGrade() > robotisation.getSignGrade(); johnson.gradeUp());
	johnson.signForm(robotisation);
	johnson.executeForm(robotisation);
	for (; johnson.getGrade() > robotisation.getExecGrade(); johnson.gradeUp());
	for (int trial = 1; trial < 10; trial++) {
		std::cout << "trial number: " << trial << std::endl;
		johnson.executeForm(robotisation);
	}
	std::cout << "TESTS OK" << std::endl;
}

// Shrubbery forms tests
void Shrubbery_tests(Bureaucrat& johnson) {
	ShrubberyCreationForm forest("Seeds4life");
	std::cout << std::endl << "---- SHRUBBERY TESTS" << std::endl;
	for (; johnson.getGrade() != 150; johnson.gradeDown());
	johnson.signForm(forest);
	for (; johnson.getGrade() > forest.getSignGrade(); johnson.gradeUp());
	johnson.executeForm(forest);
	for (; johnson.getGrade() > forest.getExecGrade(); johnson.gradeUp());
	johnson.signForm(forest);
	johnson.executeForm(forest);
	std::cout << "TESTS OK" << std::endl;
}

// Grade exeption tests
void GradeException_tests() {
	std::cout << std::endl << "---- BUREAUCRAT GRADE EXECEPTION TESTS" << std::endl;
	Bureaucrat johnson("Johnson", 150);
	try {
		Bureaucrat Dave("Dave", 189);
	}
	catch (std::exception& e) {
		std::cout << "couldnot creat bureaucrat because: " << e.what() << std::endl;
		try {
			johnson.gradeDown();
		}
		catch (std::exception& e) {
			std::cout << "couldnot downgrade johnson cause:" << e.what() << std::endl;
		}
	}
	std::cout << "TESTS OK" << std::endl;
}

int main() {

	Bureaucrat johnson("Johnson", 150);
	//AForm contract; 				// Abstract class doesnt not instantiate

	//GradeException_tests();
	//Presidential_tests(johnson);
	//Robotomy_tests(johnson);
	//Shrubbery_tests(johnson);
	Intern_tests(johnson);

	return (0);
}
