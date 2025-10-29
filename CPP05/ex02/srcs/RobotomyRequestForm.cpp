#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

// Default constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("Robotomy request", 45, 72), _target(target) {
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), _target(other._target) {
}

// Assignment operator overload
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    (void) other;
    return (*this);
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm(void)
{
    return ;
}

void		RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	this->checkPermission(executor);
    int hazard = std::rand() % 100 + 1;	// Range [1, 100]
	std::cout << "* drilling noises *" << std::endl;
	if (hazard < 51)
		std::cout << this->_target << " has been robotomized successfully !";
	else
		std::cout << "Robotony on " << this->_target << " has failed!";
	std::cout << std::endl;
}
