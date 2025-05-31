#include "Dog.hpp"

// Default constructor
Dog::Dog(void): Animal("Dog") {
    std::cout << "Dog: Default constructor called" << std::endl;
	this->_brain = new Brain();
    return ;
}

// Copy constructor
Dog::Dog(const Dog &other): Animal(other) {
    std::cout << "Dog: Copy constructor called" << std::endl;
	this->_brain = new Brain(*other._brain);
    return ;
}

// Assignment operator overload
Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog: Assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		*_brain = *other._brain;
	}
	return (*this);
}

// Destructor
Dog::~Dog(void) {
    std::cout << "Dog: Destructor called" << std::endl;
	delete this->_brain;
    return ;
}

void	Dog::makeSound(void) const {
	std::cout << "Barf" << std::endl;
}

bool	Dog::setIdea(const std::string& idea, int nb) {
	return this->_brain->setIdea(idea, nb);
}


const std::string& Dog::getIdea(int nb) const {
	return this->_brain->getIdea(nb);
}
