#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): _name(name), _weapon(weapon) {};

void	HumanA::attack() const {
	if (!_weapon)
		return ;
	std::cout << _name << ": attacks with their " << _weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon& weapon) {
	if (!_weapon)
		return ;
	_weapon.setType(weapon.getType());
	//_weapon = weapon;
}	
