#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat(void): WrongAnimal("WrongAnimal") 
{
    std::cout << "WrongCat: Default constructor called" << std::endl;
    return ;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other)
{
    std::cout << "WrongCat: Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat: Assignment operator called" << std::endl;
    this->_type = other._type;
    return (*this);
}

// Destructor
WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat: Destructor called" << std::endl;
    return ;
}

void	WrongCat::makeSound( void ) const {
	std::cout << "Wrong miaou" << std::endl;
	return ;
}
