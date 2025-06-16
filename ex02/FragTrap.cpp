#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap(void): ClapTrap() {
    std::cout << "An unknown FragTrap has arrived!" << std::endl;
	setEnergyPoints(100);
	setHitPoints(100);
	setAttackDamage(30);
    return ;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name) {
    std::cout << "FragTrap " << getName() << " has arrived!" << std::endl;
	setEnergyPoints(100);
	setHitPoints(100);
	setAttackDamage(30);
    return ;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cout << "FRAG !! Assignment operator called" << std::endl;
	setName(other.getName());
	setAttackDamage(other.getAttackDamage());
	setEnergyPoints(other.getEnergyPoints());
	setHitPoints(other.getHitPoints());
	return (*this);
}
// Destructor
FragTrap::~FragTrap(void) {
    std::cout << "FragTrap " << getName() << " has left." << std::endl;
    return ;
}

void	FragTrap::highFivesGuys(void) {
	if (getHitPoints() > 0 && getEnergyPoints() > 0) {
		std::cout << "Give me five !" << std::endl;
	} else {
		std::cout << "FragTrap " << getName();
		std::cout << " is out of service!" << std::endl;
	}

}

