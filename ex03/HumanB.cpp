#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL) {};

void	HumanB::attack() const {
	if (!_weapon) {
		std::cout << _name << " Has no weapon..." << std::endl;
		return ;
	}
	std::cout << _name << ": attacks with their " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	if (!_weapon)
		return ;
	_weapon = &weapon;
}	
