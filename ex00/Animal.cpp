#include "Animal.hpp"

// Default constructor
Animal::Animal(void)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Animal::Animal(const Animal &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
Animal::~Animal(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

