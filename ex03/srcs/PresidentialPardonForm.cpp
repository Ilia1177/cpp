#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("Presidential pardon", 5, 25), _target(target) {
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), _target(other._target) {
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    std::cout << "Cannot assign form" << std::endl;
	(void)other;
    return (*this);
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm(void) {
    std::cout << "Destructor called" << std::endl;
    return ;
}


void		PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (!this->isSigned())
		throw AForm::IsNotSigned();
	else if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox";
}
