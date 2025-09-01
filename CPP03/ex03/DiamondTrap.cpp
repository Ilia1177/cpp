#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap(void): ScavTrap(), FragTrap() {
    std::cout << "An unknown DiamonTrap has arrived" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50); //Scav
	setAttackDamage(30); // Frag
    return ;
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name) {
    std::cout << "DiamondTrap " << this->_name << " has arrived!" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50); //Scav
	setAttackDamage(30); // Frag
    return ;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	std::cout << "DIAMOND !! Assignment operator called" << std::endl;
	this->_name = other._name;
	setName(other.getName());
	setAttackDamage(other.getAttackDamage());
	setEnergyPoints(other.getEnergyPoints());
	setHitPoints(other.getHitPoints());
	return (*this);
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

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

