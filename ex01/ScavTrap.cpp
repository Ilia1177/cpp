#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap(void): ClapTrap() {
    std::cout << "An unknown ScavTrap has arrived!" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
    return ;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name) {
    std::cout <<  "ScavTrap " << name << " has arrived!" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
    return ;
}

// Destructor
ScavTrap::~ScavTrap(void)
{
    std::cout << "Scavtrap " << getName() << " is gone." << std::endl;
    return ;
}

void ScavTrap::attack(const std::string& target) {
	if (getEnergyPoints() > 0 && getHitPoints() > 0) {
		std::cout << "ScavTrap " << getName();
		std::cout << " attacks " << target << ", ";
		std::cout << " causing " << getAttackDamage();
		std::cout << " points of damage!" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
	else {
		std::cout << "ScavTrap " << getName();
		std::cout << " is out of service!" << std::endl;
	}
}
void	ScavTrap::guardGate( void ) {
	if (getEnergyPoints() > 0 && getHitPoints() > 0) {
		std::cout << "ScavTrap " << getName();
		std::cout << " is now in Gate keeper mode!" << std::endl;
	} else {
		std::cout << "ScavTrap " << getName();
		std::cout << " is out of service!" << std::endl;
	}
}
