#include "AMateria.hpp"

// Default constructor
AMateria::AMateria(void): _type(NULL) {
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Default constructor
AMateria::AMateria(const std::string& type): _type(type) {
    std::cout << "Default constructor called" << std::endl;
    return ;
}
// Copy constructor
AMateria::AMateria(const AMateria &other): _type(other._type) {
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
AMateria &AMateria::operator=(const AMateria &other) {
	if (this->_type != other.getType()) {
		std::cout << "Impossible asignement... type doesnt match" << std::endl;
		return (*this);
	} else if (this != &other) {
		std::cout << "Assignment operator called" << std::endl;
		this->_type = other.getType();
	}
    return (*this);
}

// Destructor
AMateria::~AMateria(void) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

const std::string& AMateria::getType(void) const {
	return this->_type;
}




