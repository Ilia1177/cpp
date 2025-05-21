#include "Dog.hpp"

// Default constructor
Dog::Dog(void)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Dog::Dog(const Dog &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
Dog::~Dog(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

void	Dog::makeSound(void) const {
	std::cout << "Barf" << std::endl;
}
