#include "Cure.hpp"

// Default constructor
Cure::Cure(void): AMateria("cure") {
#if PRINT
    std::cout << "Cure:: Default constructor called" << std::endl;
#endif
    return ;
}

// Copy constructor
Cure::Cure(const Cure &other): AMateria(other) {
#if PRINT
    std::cout << "Cure:: Copy constructor called" << std::endl;
#endif
    return ;
}

// Assignment operator overload
Cure &Cure::operator=(const Cure &other) {
#if PRINT
    std::cout << "Cure:: Assignment operator called" << std::endl;
#endif
	AMateria::operator=(other);
    return (*this);
}

// Destructor
Cure::~Cure(void) {
#if PRINT
    std::cout << "Cure:: Destructor called" << std::endl;
#endif
    return ;
}

AMateria *Cure::clone( void ) const {
	return new Cure;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
