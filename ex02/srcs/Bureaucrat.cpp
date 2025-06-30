#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name) {
    std::cout << "Default constructor called" << std::endl;
	if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
	} else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
	}
    _grade = grade;
    return ;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade) {
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    std::cout << "Assignment operator called" << std::endl;
	this->_grade = other.getGrade();
    return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat(void) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

void Bureaucrat::gradeUp() {
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::gradeDown() {
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}

const std::string& Bureaucrat::getName(void) const {
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void	Bureaucrat::signForm(AForm& form) const {
	try {
		form.beSigned(*this);
	}
	catch (std::exception& e) {
		std::cout << this->getName() << " couldn't sign " << form.getName();
		std::cout << " because: " << e.what() << std::endl;
		return ;
	}
	std::cout << this->getName() << " signed " << form.getName() << std::endl;
}

void	Bureaucrat::executeForm(const AForm& form) const {
	try {
		form.execute(*this);
		std::cout << *this << " executed form: " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << this->getName() << " couldn t execute form " << form.getName();
		std::cout << " because: " << e.what() << std::endl;
	}
}
const char* Bureaucrat::GradeTooHighException::what() const throw() {
		return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
		return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& admin) {
    os << "Name: " << admin.getName() << ", Grade: " << admin.getGrade();
    return os;
}
