#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat(void)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

