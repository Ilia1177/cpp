#include <Cat.hpp>

// Default constructor
Cat::Cat(void): Animal("Cat") {
    std::cout << "Cat: Default constructor called" << std::endl;
	_brain = new Brain();
    return ;
}

// Copy constructor
Cat::Cat(const Cat &other): Animal(other) {
    std::cout << "Cat: Copy constructor called" << std::endl;
	this->_brain = new Brain(*other._brain);
    return ;
}

// Assignment operator overload
Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat: Assignment operator called" << std::endl;
	if (this != &other)	{
        Animal::operator=(other); // Call base assignment
        *_brain = *other._brain;  // Deep copy Brain content
    }
    return (*this);
}

// Destructor
Cat::~Cat(void) {
    std::cout << "Cat: Destructor called" << std::endl;
	delete this->_brain;
    return ;
}

void	Cat::makeSound(void) const {
	std::cout << "Miaou" << std::endl;
}

bool	Cat::setIdea(const std::string& idea, int nb) {
	return this->_brain->setIdea(idea, nb);
}


const std::string& Cat::getIdea(int nb) const {
	return this->_brain->getIdea(nb);
}
