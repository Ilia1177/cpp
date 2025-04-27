#include "Fixed.hpp"

// Default constructor
Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
	_n = 0;
    return ;
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
	_n = other.getRawBits();
    return ;
}

// Assignment operator overload
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Assignment operator called" << std::endl;
	_n = other.getRawBits();
    return (*this);
}

// Destructor
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
	_n = 0;
    return ;
}
void Fixed::setRawBits( int const raw ){
    std::cout << "setRawBits function called" << std::endl;
	_n = raw;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits function called" << std::endl;
	return (_n);
}
