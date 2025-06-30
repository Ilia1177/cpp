#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

// Default constructor
Intern::Intern(void) {
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Intern::Intern(const Intern &other) {
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
Intern &Intern::operator=(const Intern &other) {
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
Intern::~Intern(void) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) const {
	AForm *contract;

	std::string availableForms[3] = {	"Shrubbery creation",
										"Robotomy request",
										"Presidential pardon" };

	for (int i = 0; name != availableForms[i] && i < 3; i++);

	if (name == "Robotomy request")
		contract = new RobotomyRequestForm(target);
	else if (name == "Shrubbery creation")
		contract = new ShrubberyCreationForm(target);
	else if (name == "Presidential pardon")
		contract = new PresidentialPardonForm(target);
	else 
		throw Intern::InvalidTypeForm();
	std::cout << "Intern creates " << contract->getName() << std::endl;
	return contract;
}

const char* Intern::InvalidTypeForm::what() const throw() {
	return "Form's name does not exist";
}
