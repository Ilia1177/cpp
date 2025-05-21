#include <Animal.hpp>

// Default constructor
Animal::Animal(void) {
    std::cout << "Animal: Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Animal::Animal(const Animal &other) {
    std::cout << "Animal: Copy constructor called" << std::endl;
    this->type = other.type;
    return ;
}

// Assignment operator overload
Animal &Animal::operator=(const Animal &other) {
    std::cout << "Animal: Assignment operator called" << std::endl;
    this->type = other.type;
    return (*this);
}

// Destructor
Animal::~Animal(void)
{
    std::cout << "Animal: Destructor called" << std::endl;
    return ;
}

void	Animal::makeSound(void) const {
	return ;
}
