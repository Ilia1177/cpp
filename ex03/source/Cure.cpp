#include "Cure.hpp"

// Default constructor
Cure::Cure(void): _type("cure") {
    std::cout << "Cure:: Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Cure::Cure(const Cure &other): AMateria(other) {
    std::cout << "Cure:: Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
Cure &Cure::operator=(const Cure &other) {
    std::cout << "Cure:: Assignment operator called" << std::endl;
	AMateria::operator=(other);
    return (*this);
}

// Destructor
Cure::~Cure(void) {
    std::cout << "Cure:: Destructor called" << std::endl;
    return ;
}

AMateria *Cure::clone( void ) {
	return new Cure;
}
