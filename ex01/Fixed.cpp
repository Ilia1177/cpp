#include "Fixed.hpp"

//	Destructor
Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

//	Default constructor
Fixed::Fixed(void): _rawValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

//	Copy constructor
Fixed::Fixed(const Fixed &other): _rawValue(other.getRawBits()) {
    std::cout << "Copy constructor called" << std::endl;
}

//	Assignment operator overload
Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Assignment operator called" << std::endl;
    if (this != &other) {
        setRawBits(other.getRawBits());
    }
    return (*this);
}

std::ostream &operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

Fixed::Fixed(const int n) {
    std::cout << "Constructor called" << std::endl;
	setRawBits(n << _fractionalBits);
}

Fixed::Fixed(const float f) {
    std::cout << "Constructor called" << std::endl;
	setRawBits(static_cast<int>(roundf(f * (1 << _fractionalBits))));
}

// Right-shift to undo scaling
int Fixed::toInt(void) const {
    return _rawValue >> _fractionalBits;
}

float Fixed::toFloat(void) const {
	float	f;

	f = static_cast<float>(_rawValue) / (1 << _fractionalBits);
    return f;
}

void Fixed::setRawBits( int const raw ){
    std::cout << "setRawBits function called" << std::endl;
	_rawValue = raw;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits function called" << std::endl;
	return (_rawValue);
}
