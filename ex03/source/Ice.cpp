#include "Ice.hpp"

// Default constructor
Ice::Ice(void): AMateria("ice") {
#if PRINT
    std::cout << "Ice:: Default constructor called" << std::endl;
#endif
    return ;
}

// Copy constructor
Ice::Ice(const Ice &other): AMateria(other) {
#if PRINT
    std::cout << "Ice:: Copy constructor called" << std::endl;
#endif
    return ;
}

// Assignment operator overload
Ice &Ice::operator=(const Ice &other) {
#if PRINT
    std::cout << "Ice:: Assignment operator called" << std::endl;
#endif
	AMateria::operator=(other);
    return (*this);
}

// Destructor
Ice::~Ice(void) {
#if PRINT
    std::cout << "Ice:: Destructor called" << std::endl;
#endif
    return ;
}

AMateria *Ice::clone( void ) const {
	return new Ice;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoot an ice bolt at " << target.getName() << " " << std::endl;
}
