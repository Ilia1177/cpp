#include <Animal.hpp>

// Default constructor
Animal::Animal(void): _type("Animal") {
    std::cout << "Animal: Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Animal::Animal(const Animal &other) {
    std::cout << "Animal: Copy constructor called" << std::endl;
    this->_type = other._type;
    return ;
}

Animal::Animal(const std::string& type) {
    std::cout << "Animal: Constructor called" << std::endl;
    this->_type = type;
    return ;
}

// Assignment operator overload
Animal &Animal::operator=(const Animal &other) {
    std::cout << "Animal: Assignment operator called" << std::endl;
    this->_type = other._type;
    return (*this);
}

// Destructor
Animal::~Animal(void) {
    std::cout << "Animal: Destructor called" << std::endl;
    return ;
}
const std::string& Animal::getType() const {
	return(_type);
}

void	Animal::makeSound(void) const {
	return ;
}
