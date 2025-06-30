#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void Intern_tests(Bureaucrat& johnson) {
	std::cout << std::endl << "---- INTERN TESTS" << std::endl;
	Intern marc;
	AForm *newForm;

	try {
		newForm = marc.makeForm("Shrubbery pardon", "bigHouse");
		for (; johnson.getGrade() > newForm->getSignGrade(); johnson.gradeUp());
		johnson.signForm(*newForm);
		for (; johnson.getGrade() > newForm->getExecGrade(); johnson.gradeUp());
		johnson.executeForm(*newForm);
	}
	catch (std::exception& e) {
		std::cout << "Invalid action because: " << e.what() << std::endl;
	}

	try {
		newForm = marc.makeForm("Shrubbery creation", "bigHouse");
		for (; johnson.getGrade() > newForm->getSignGrade(); johnson.gradeUp());
		johnson.signForm(*newForm);
		for (; johnson.getGrade() > newForm->getExecGrade(); johnson.gradeUp());
		johnson.executeForm(*newForm);
	}
	catch (std::exception& e) {
		std::cout << "Invalid action because: " << e.what() << std::endl;
	}
	delete newForm;
}

void Presidential_tests(Bureaucrat& johnson) {
	// PresidentialPardon tests
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

void Robotomy_tests(Bureaucrat& johnson) {
	// Robotomize tests
	std::srand(std::time(0)); 
	RobotomyRequestForm robotisation("R2D2");
	std::cout << std::endl << "---- ROBOTISATION TESTS" << std::endl;
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
}

void Shrubbery_tests(Bureaucrat& johnson) {
	// Shrubbery tests
	ShrubberyCreationForm forest("Seeds4life");
	std::cout << std::endl << "---- SHRUBBERY TESTS" << std::endl;
	for (; johnson.getGrade() != 150; johnson.gradeDown());
	johnson.signForm(forest);
	for (; johnson.getGrade() > forest.getSignGrade(); johnson.gradeUp());
	johnson.executeForm(forest);
	for (; johnson.getGrade() > forest.getExecGrade(); johnson.gradeUp());
	johnson.signForm(forest);
	johnson.executeForm(forest);
}

void GradeException_test() {
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
}

int main() {

	Bureaucrat johnson("Johnson", 150);

//	GradeExeption_tests();
//	Presidential_tests(johnson);
//	Robotomy_tests(johnson);
//	Shrubbery_tests(johnson);
	Intern_tests(johnson);

	return (0);
}
