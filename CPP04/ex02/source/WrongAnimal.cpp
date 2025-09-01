#include "WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal(void)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "WrongAnimal: Copy constructor called" << std::endl;
    this->_type = other.getType();
    return ;
}

WrongAnimal::WrongAnimal(const std::string& type)
{
    std::cout << "WrongAnimal: Constructor called" << std::endl;
    this->_type = type;
    return ;
}
// Assignment operator overload
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "WrongAnimal: Assignment operator called" << std::endl;
    this->_type = other._type;
    return (*this);
}

const std::string& WrongAnimal::getType( void ) const {
	return(_type);
}

void	WrongAnimal::makeSound( void ) const {
	return ;
}

// Destructor
WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal: Destructor called" << std::endl;
    return ;
}

