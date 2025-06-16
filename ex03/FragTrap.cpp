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

// Destructor
FragTrap::~FragTrap(void) {
    std::cout << "FragTrap " << getName() << " has left." << std::endl;
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

void	FragTrap::highFivesGuys(void) {
	if (getHitPoints() > 0 && getEnergyPoints() > 0) {
		std::cout << "Give me five !" << std::endl;
	} else {
		std::cout << "FragTrap " << getName();
		std::cout << " is out of service!" << std::endl;
	}

}

void FragTrap::attack(const std::string& target) {
	if (getEnergyPoints() > 0 && getHitPoints() > 0) {
		std::cout << "FragTrap " << getName();
		std::cout << " attacks " << target << ", ";
		std::cout << " causing " << getAttackDamage();
		std::cout << " points of damage!" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
	else {
		std::cout << "FragTrap " << getName();
		std::cout << " is out of service!" << std::endl;
	}
}

void FragTrap::takeDamage(unsigned int amount) {
	if (getEnergyPoints() > 0 && getHitPoints() > 0) {
		std::cout << "FragTrap " << getName();
		std::cout << " got " << amount;
		std::cout << " points of damage!" << std::endl;
		if (amount >= getHitPoints()) {
			setHitPoints(0);
		} else {
			setHitPoints(getHitPoints() - amount);
		}
	}
	else {
		std::cout << "FragTrap " << getName();
		std::cout << " is out of service!" << std::endl;
	}
}

void FragTrap::beRepaired(unsigned int amount) {
	if (getEnergyPoints() > 0 && getHitPoints() > 0) {
		std::cout << "FragTrap " << getName();
		std::cout << " got repaired by " << amount;
		std::cout << " hit points!" << std::endl;
		setHitPoints(getHitPoints() + amount);
		setEnergyPoints(getEnergyPoints() - 1);
	}
	else {
		std::cout << "FragTrap " << getName();
		std::cout << " is out of service!" << std::endl;
	}
}
