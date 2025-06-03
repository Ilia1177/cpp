#include "Ice.hpp"

// Default constructor
Ice::Ice(void): AMateria("ice") {
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

AMateria *Ice::clone( void ) const {
	return new Ice;
}

void Ice::use(ICharacter& target) {
	if (!target)
		return ;
	std::cout << "* shoot an ice bolt at " << target.getName() << std::endl;
}
