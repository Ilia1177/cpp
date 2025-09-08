#include "AForm.hpp"
#include "Bureaucrat.hpp"
// Default constructor
AForm::AForm(const std::string& name, int gradeToExecute, int gradeToSign): 
	_name(name), _signed(false), _gradeToExecute(clamp(gradeToExecute, 1, 150)), _gradeToSign(clamp(gradeToSign, 1, 150)) {
    std::cout << "Default constructor called" << std::endl;
	if (gradeToExecute > 150) {
		throw AForm::GradeTooLowException();
	} else if (gradeToExecute < 1) {
		throw AForm::GradeTooHighException();
	}
	if (gradeToSign > 150) {
		throw AForm::GradeTooLowException();
	} else if (gradeToSign < 1) {
		throw AForm::GradeTooHighException();
	}
}

// Copy constructor
AForm::AForm(const AForm &other): 
	_name(other._name), 
	_signed(false), 
	_gradeToExecute(other._gradeToExecute),
	_gradeToSign(other._gradeToSign) {
    return ;
}

// Assignment operator overload
AForm &AForm::operator=(const AForm &other) {
	if (this != &other) {
		_signed = other._signed;
	}
    return (*this);
}

// Destructor
AForm::~AForm(void) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

// getters
const std::string& AForm::getName() const {
	return _name;
}

bool AForm::isSigned() const {
	return _signed;
}

int	AForm::getExecGrade() const {
	return _gradeToExecute;
}

int	AForm::getSignGrade() const {
	return _gradeToSign;
}

void	AForm::beSigned(const Bureaucrat& signer) {
	if (signer.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	_signed = true;
}
// exceptions
const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char* AForm::IsNotSigned::what() const throw() {
	return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form's name................: " << form.getName() << std::endl;
	os << "Signed.....................: " << (form.isSigned() ? "yes" : "no") << std::endl;
	os << "Required Grade to execute..: " << form.getExecGrade() << std::endl;
	os << "Required Grade to sign.....: " << form.getSignGrade() << std::endl;
    return (os);
}
