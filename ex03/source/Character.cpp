#include "Character.hpp"

// Default constructor
Character::Character(void) {
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = NULL;
	}
    std::cout << "CHARACTER:: Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Character::Character(const Character &other) {
	for (int i = 0; i < 4; ++i) {
		std::cout << "CHARACTER:: Copy constructor called" << std::endl;
		if (other._inventory[i]) {
			_inventory[i] = new AMateria(other._inventory[i]);
		} else {
			_inventory[i] = NULL;
		}
	}
    return ;
}

// Assignment operator overload
Character &Character::operator=(const Character &other) {
	if (this != &other) {
		std::cout << "CHARACTER:: Assignment operator called" << std::endl;
		for (int i = 0; i < 4; ++i) {
			*_inventory[i] = *other._inventory[i];
		}
	}
    return (*this);
}

// Destructor
Character::~Character(void) {
    std::cout << "CHARACTER:: Destructor called" << std::endl;
	for (int i = 0; i < 4; ++i) {
		if (_inventory[i])
		delete _inventory[i];
	}
    return ;
}

