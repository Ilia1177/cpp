#include "Fixed.hpp"

//	Destructor
Fixed::~Fixed(void) {}

//	Constructors
Fixed::Fixed(void): _rawValue(0) {}

Fixed::Fixed(const float f) {
	setRawBits(static_cast<int>(roundf(f * (1 << _fractionalBits))));
}

Fixed::Fixed(const int n) {
	setRawBits(n << _fractionalBits);
}

Fixed::Fixed(const Fixed &other): _rawValue(other.getRawBits()) {
}	//	Copy constructor

//	Assignment operator overload
Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        setRawBits(other.getRawBits());
    }
    return (*this);
}

//	Logic operators overload
bool Fixed::operator>(const Fixed &other) const {
	if (this->_rawValue > other._rawValue)
		return (true);
    return (false);
}

bool Fixed::operator<(const Fixed &other) const {
	if (this->_rawValue < other._rawValue)
		return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed &other) const {
	if (this->_rawValue <= other._rawValue)
		return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed &other) const {
	if (this->_rawValue >= other._rawValue)
		return (true);
    return (false);
}

// BITS OPERATIONS
Fixed Fixed::operator+(const Fixed &other) const {
	Fixed	result;

	result._rawValue = this->_rawValue + other._rawValue;
    return (result);
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed	result;

	result._rawValue = this->_rawValue - other._rawValue;
    return (result);
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed	result;

	result._rawValue = (this->_rawValue * other._rawValue) >> _fractionalBits;
    return (result);
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed	result(0);

	if (other._rawValue == 0) {
		std::cout << "Error: 0 divisions" << std::endl;
		return (result);
	}
	result._rawValue = (this->_rawValue << _fractionalBits) / other._rawValue;
    return (result);
}

// Increment / Decrement
Fixed &Fixed::operator++() {
	++this->_rawValue;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed	temp = *this;
	++this->_rawValue;
	return (temp);
}

Fixed &Fixed::operator--() {
    --this->_rawValue;
    return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed	temp = *this;
	--this->_rawValue;
    return (temp);
}

const Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}
// Insert the floating-point representation
// Return the stream for chaining (e.g., `cout << a << b`)
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
	return os;
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
	_rawValue = raw;
}

int Fixed::getRawBits( void ) const {
	return (_rawValue);
}
