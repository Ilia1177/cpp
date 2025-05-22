#include "Dog.hpp"

// Default constructor
Dog::Dog(void): Animal("Dog") {
    std::cout << "Dog: Default constructor called" << std::endl;
	this->_brain = new Brain();
    return ;
}

// Copy constructor
Dog::Dog(const Dog &other) {
    std::cout << "Dog: Copy constructor called" << std::endl;
	this->_type = other._type;
	this->_brain = new Brain(other._brain);
    return ;
}

// Assignment operator overload
Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog: Assignment operator called" << std::endl;
	this->_type = other._type;
	this->_brain = other._brain;
    return (*this);
}

// Destructor
Dog::~Dog(void) {
	delete this->_brain;
    std::cout << "Dog: Destructor called" << std::endl;
    return ;
}

void	Dog::makeSound(void) const {
	std::cout << "Barf" << std::endl;
}
