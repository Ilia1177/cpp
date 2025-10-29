#include "Form.hpp"
#include "Bureaucrat.hpp"
// Default constructor
Form::Form(const std::string& name, int gradeToExecute, int gradeToSign): 
	_name(name), _signed(false), _gradeToExecute(clamp(gradeToExecute, 1, 150)), _gradeToSign(clamp(gradeToSign, 1, 150)) {
    std::cout << "Default constructor called" << std::endl;
	if (gradeToExecute > 150) {
		throw Form::GradeTooLowException();
	} else if (gradeToExecute < 1) {
		throw Form::GradeTooHighException();
	}
	if (gradeToSign > 150) {
		throw Form::GradeTooLowException();
	} else if (gradeToSign < 1) {
		throw Form::GradeTooHighException();
	}
}

// Copy constructor
Form::Form(const Form &other): 
	_name(other._name), 
	_signed(false), 
	_gradeToExecute(other._gradeToExecute),
	_gradeToSign(other._gradeToSign) {
    return ;
}

// Assignment operator overload
Form &Form::operator=(const Form &other) {
	if (this != &other) {
		_signed = other._signed;
	}
    return (*this);
}

// Destructor
Form::~Form(void) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

// getters
const std::string& Form::getName() const {
	return _name;
}

bool Form::isSigned() const {
	return _signed;
}

int	Form::getExecGrade() const {
	return _gradeToExecute;
}

int	Form::getSignGrade() const {
	return _gradeToSign;
}

void	Form::beSigned(const Bureaucrat& signer) {
	if (signer.getGrade() > this->getSignGrade())
		throw Form::GradeTooLowException();
	_signed = true;
}
// exceptions
const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << form.getName() << std::endl;
	os << "Signed: " << form.isSigned() << std::endl;
	os << "Required Grade to execute: " << form.getExecGrade() << std::endl;
	os << "Required Grade to sign:    " << form.getSignGrade() << std::endl;
    return os;
}
