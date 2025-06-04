#include "Point.hpp"

// Default constructor
Point::Point(void): _x(0), _y(0) {
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Point::Point(const Fixed x, const Fixed y): _x(x), _y(y) {
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Point::Point(const float x, const float y): _x(x), _y(y) {
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Point::Point(const Point &other): _x(other._x), _y(other._y) {
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
Point Point::operator=(const Point &other) {
    std::cout << "Assignment operator called" << std::endl;
	Point p(other);
    return (p);
}
// Destructor
Point::~Point(void) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed Point::getY( void ) const { return _y; }

Fixed Point::getX( void ) const { return _x; }
