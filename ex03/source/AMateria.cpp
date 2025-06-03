#include "AMateria.hpp"

// Default constructor
AMateria::AMateria(void): _type(NULL) {
#if PRINT
    std::cout << "AMateria:: Default constructor called" << std::endl;
#endif
    return ;
}

// Default constructor
AMateria::AMateria(const std::string& type): _type(type) {
#if PRINT
    std::cout << "AMateria:: Default constructor called" << std::endl;
#endif
    return ;
}
// Copy constructor
AMateria::AMateria(const AMateria &other): _type(other._type) {
#if PRINT
    std::cout << "AMateria:: Copy constructor called" << std::endl;
#endif
    return ;
}

// Assignment operator overload
AMateria &AMateria::operator=(const AMateria &other) {
	if (this->_type != other.getType()) {
		std::cout << "Impossible asignement... type doesnt match" << std::endl;
		return (*this);
	} else if (this != &other) {
#if PRINT
		std::cout << "AMaterie:: Assignment operator called" << std::endl;
#endif
		this->_type = other.getType();
	}
    return (*this);
}

// Destructor
AMateria::~AMateria(void) {
#if PRINT
    std::cout << "AMateria:: Destructor called" << std::endl;
#endif
    return ;
}

const std::string& AMateria::getType(void) const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
#if PRINT
	std::cout << "use of AMateria" << std::endl;
#endif
	if (getType() == "cure")
		std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	else if (getType() == "ice")
		std::cout << "* shoot an ice bolt at " << target.getName() << std::endl;
}
