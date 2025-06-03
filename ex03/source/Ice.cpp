#include "Ice.hpp"

// Default constructor
Ice::Ice(void): _type("ice") {
    std::cout << "Ice:: Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Ice::Ice(const Ice &other): AMateria(other) {
    std::cout << "Ice:: Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
Ice &Ice::operator=(const Ice &other) {
    std::cout << "Ice:: Assignment operator called" << std::endl;
	AMateria::operator=(other);
    return (*this);
}

// Destructor
Ice::~Ice(void) {
    std::cout << "Ice:: Destructor called" << std::endl;
    return ;
}

AMateria *Cure::clone( void ) {
	return new Cure;
}
