#include "MateriaSource.hpp"

// Default constructor
MateriaSource::MateriaSource(void) {
	for (size_t i = 0; i < 4; i++) {
		_stock[i] = NULL;	
	}
#if PRINT
    std::cout << "Default constructor called" << std::endl;
#endif
    return ;
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource &other) {
	for (size_t i = 0; i < 4; i++) {
		if (!other._stock[i]) {
			_stock[i] = NULL;
		} else {
			_stock[i] = other._stock[i]->clone();
		}
	}
#if PRINT
    std::cout << "Copy constructor called" << std::endl;
#endif
    return ;
}

// Assignment operator overload
MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	for (size_t i = 0; i < 4; i++) {
		if (_stock[i])
			delete _stock[i];
		if (!other._stock[i]) {
			_stock[i] = NULL;
		} else {
			_stock[i] = other._stock[i]->clone();
		}
		
	}
#if PRINT
    std::cout << "Assignment operator called" << std::endl;
#endif
    (void) other;
    return (*this);
}

// Destructor
MateriaSource::~MateriaSource(void) {
	for (size_t i = 0; i < 4; i++) {
		if (_stock[i])
			delete _stock[i];
	}
#if PRINT
    std::cout << "Crafting::Destructor called" << std::endl;
#endif
    return ;
}

void MateriaSource::learnMateria(AMateria* source) {
	for (size_t i = 0; i < 4; i++) {
		if (!_stock[i] && source) {
			_stock[i] = source;
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (size_t i = 0; i < 4; i++) {
		if (_stock[i] && _stock[i]->getType() == type)
			return _stock[i]->clone();
	}
	return (NULL);
}
