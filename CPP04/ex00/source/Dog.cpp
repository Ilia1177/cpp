#include "Dog.hpp"

// Default constructor
Dog::Dog(void): Animal("Dog") {
    std::cout << "Dog: Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Dog::Dog(const Dog &other) {
    std::cout << "Dog: Copy constructor called" << std::endl;
	this->_type = other._type;
    return ;
}

// Assignment operator overload
Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog: Assignment operator called" << std::endl;
	this->_type = other._type;
    return (*this);
}

// Destructor
Dog::~Dog(void) {
    std::cout << "Dog: Destructor called" << std::endl;
    return ;
}

void	Dog::makeSound(void) const {
	std::cout << "Barf" << std::endl;
}
