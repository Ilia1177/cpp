#include "Dog.hpp"

// Default constructor
Dog::Dog(void)
{
    std::cout << "Dog: Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Dog::Dog(const Dog &other)
{
    std::cout << "Dog: Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog: Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
Dog::~Dog(void)
{
    std::cout << "Dog: Destructor called" << std::endl;
    return ;
}

void	Dog::makeSound(void) const {
	std::cout << "Barf" << std::endl;
}
