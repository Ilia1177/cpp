#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap(void): ClapTrap() {
    std::cout << "An unknown DiamonTrap has arrived" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50); //Scav
	setAttackDamage(30); // Frag
    return ;
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), _name(name) {
    std::cout << "DiamondTrap " << this->_name << " has arrived!" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50); //Scav
	setAttackDamage(30); // Frag
    return ;
}

// Destructor
DiamondTrap::~DiamondTrap(void) {
    std::cout << "DiamondTrap Destructor called" << std::endl;
    return ;
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "Clap trap name: " << ClapTrap::getName() << std::endl;
	std::cout << "Diamond name: " << this->_name << std::endl;
}
