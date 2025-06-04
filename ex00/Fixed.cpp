#include "Fixed.hpp"

// Default constructor
Fixed::Fixed(void): _rawValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
	_rawValue = other.getRawBits();
}

// Assignment operator overload
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Assignment operator called" << std::endl;
	_rawValue = other.getRawBits();
    return (*this);
}

// Destructor
Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits( int const raw ){
    std::cout << "setRawBits function called" << std::endl;
	_rawValue = raw;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits function called" << std::endl;
	return (_rawValue);
}
