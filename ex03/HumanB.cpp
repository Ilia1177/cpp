#include "Weapon.hpp"
//	Weapon&	HumanB::getWeapon() const {
//		return (_weapon);
//	}

HumanB::HumanB(std::string name): _name(name), _weapon(NULL) {};

void	HumanB::attack() const {
	std::cout << _name << ": attacks with their " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	//_weapon.setType(weapon.getType());
	_weapon = &weapon;
}	
