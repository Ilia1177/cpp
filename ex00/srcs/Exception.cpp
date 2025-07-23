#include "Exception.hpp"

// Default constructor
Exception::Exception(void)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Exception::Exception(const Exception &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
Exception &Exception::operator=(const Exception &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
Exception::~Exception(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

