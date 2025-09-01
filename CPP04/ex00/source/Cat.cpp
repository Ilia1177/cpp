#include <Cat.hpp>

// Default constructor
Cat::Cat(void): Animal("Cat") {
    std::cout << "Cat: Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Cat::Cat(const Cat &other) {
    std::cout << "Cat: Copy constructor called" << std::endl;
	this->_type = other._type;
    return ;
}

// Assignment operator overload
Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat: Assignment operator called" << std::endl;
	this->_type = other._type;
    return (*this);
}

// Destructor
Cat::~Cat(void) {
    std::cout << "Cat: Destructor called" << std::endl;
    return ;
}

void	Cat::makeSound(void) const {
	std::cout << "Miaou" << std::endl;
}
