#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("Presidential pardon", 5, 25), _target(target) {
    return ;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), _target(other._target) {
    return ;
}

// Assignment operator overload
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	(void)other;
    return (*this);
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm(void) {
    return ;
}


void		PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	this->checkPermission(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
