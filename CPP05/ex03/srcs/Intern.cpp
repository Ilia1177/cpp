#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

// Default constructor
Intern::Intern(void) {
    return ;
}

// Copy constructor
Intern::Intern(const Intern &other) {
    (void) other;
    return ;
}

// Assignment operator overload
Intern &Intern::operator=(const Intern &other) {
    (void) other;
    return (*this);
}

// Destructor
Intern::~Intern(void) {
    return ;
}

AForm* Intern::makePresidentialForm(const std::string& target) const {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeRobotomyForm(const std::string& target) const {
	return new RobotomyRequestForm(target);
}

AForm* Intern::makeShrubberyForm(const std::string& target) const {
	return new ShrubberyCreationForm(target);
}


AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
	std::string availableForms[3] = 							{	"shrubbery creation",
																	"robotomy request",
																	"presidential pardon" };
	AForm* (Intern::*actualForm[3])(const std::string&) const = {	&Intern::makeShrubberyForm,
																	&Intern::makeRobotomyForm,
																	&Intern::makePresidentialForm };

	for (int i = 0; i < 3; i++) {
		if (name == availableForms[i]) {
			std::cout << "Intern creates " << availableForms[i] << std::endl;
			return (this->*actualForm[i])(target);
		}
	}
	throw Intern::InvalidTypeForm();
}

const char* Intern::InvalidTypeForm::what() const throw() {
	return "Form's name does not exist";
}
