#include "Cure.hpp"

// Default constructor
Cure::Cure(void): AMateria("cure") {
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

AMateria *Cure::clone( void ) const {
	return new Cure;
}

void Cure::use(ICharacter& target) {
	if (!target)
		return ;
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
