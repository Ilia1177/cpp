#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

// Default constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("Robotomy request", 45, 72), _target(target) {
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), _target(other._target) {
    std::cout << "Copy constructor called" << std::endl;
}

// Assignment operator overload
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    std::cout << "Cannot assign form" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm(void) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

void		RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (!this->isSigned())
		throw AForm::IsNotSigned();
	else if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();

    int hazard = std::rand() % 100 + 1;				// Range [1, 100]
	std::cout << "* drilling noises *" << std::endl;
	if (hazard < 50)
		std::cout << this->_target << " has been robotomized successfully !";
	else if (hazard > 50)
		std::cout << "Robotony on " << this->_target << " has failed!";
	std::cout << std::endl;
}
