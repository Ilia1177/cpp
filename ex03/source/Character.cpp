#include "Character.hpp"

// Default constructor
Character::Character(void): _name("Unknown"){
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = NULL;
	}
#if PRINT
    std::cout << "CHARACTER:: Default constructor called" << std::endl;
#endif
    return ;
}

// Default constructor
Character::Character(const std::string& name): _name(name){
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = NULL;
	}
#if PRINT
    std::cout << "CHARACTER:: Default constructor called" << std::endl;
#endif
    return ;
}

// Copy constructor
Character::Character(const Character &other) {
#if PRINT
	std::cout << "CHARACTER:: Copy constructor called" << std::endl;
#endif
	for (int i = 0; i < 4; ++i) {
		if (other._inventory[i]) {
			delete _inventory[i];
			_inventory[i] = other._inventory[i]->clone();
		} else {
			_inventory[i] = NULL;
		}
	}
    return ;
}

// Assignment operator overload
Character &Character::operator=(const Character &other) {
#if PRINT
		std::cout << "CHARACTER:: Assignment operator called" << std::endl;
#endif
	if (this != &other) {
		for (int i = 0; i < 4; ++i) {
			if (_inventory[i])
				delete _inventory[i];
			if (other._inventory[i]) {
				_inventory[i] = other._inventory[i]->clone();
			} else {
				_inventory[i] = NULL;
			}
		}
	}
    return (*this);
}

// Destructor
Character::~Character(void) {
#if PRINT
    std::cout << "CHARACTER:: Destructor called" << std::endl;
#endif
	for (size_t i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
    return ;
}

const std::string& Character::getName( void ) const {
	return _name;
}

void	Character::equip(AMateria* m) {
#if PRINT
	std::cout << "Character:: equip materia" << std::endl;
#endif
	for (size_t i = 0; i < 4; ++i) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		_inventory[idx] = NULL;
#if PRINT
		std::cout << "Character:: unequip" << std::endl;
#endif
	}
}

void	Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && _inventory[idx]) {
		_inventory[idx]->use(target);
#if PRINT
		std::cout << "Character:: use" << std::endl;
#endif
	}
}

AMateria *Character::getMateria(int idx) const {
	if (idx >= 0 && idx < 4)
		return (_inventory[idx]);
	return NULL;
}
