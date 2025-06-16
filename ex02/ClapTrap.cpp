#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap(void):
	_name("Unknown"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "An unknown ClapTrap has arrived" << std::endl;
    return ;
}

ClapTrap::ClapTrap(const std::string& name):
	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << name << " has arrived!" << std::endl;
    return ;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other): 
	_name(other.getName()),
	_hitPoints(other.getHitPoints()),
	_energyPoints(other.getEnergyPoints()),
	_attackDamage(other.getAttackDamage()) {
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "Assignment operator called" << std::endl;
	setName(other.getName());
    setAttackDamage(other.getAttackDamage());
	setEnergyPoints(other.getEnergyPoints());
	setHitPoints(other.getHitPoints());
    return (*this);
}

// Destructor
ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap " << getName() << " has left." << std::endl;
    return ;
}

void ClapTrap::attack(const std::string& target) {
	if (getEnergyPoints() > 0 && getHitPoints() > 0) {
		std::cout << "ClapTrap " << getName();
		std::cout << " attacks " << target << ", ";
		std::cout << " causing " << getAttackDamage();
		std::cout << " points of damage!" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
	else {
		std::cout << "ClapTrap " << getName();
		std::cout << " is out of service!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (getEnergyPoints() > 0 && getHitPoints() > 0) {
		std::cout << "ClapTrap " << getName();
		std::cout << " got " << amount;
		std::cout << " points of damage!" << std::endl;
		if (amount >= getHitPoints()) {
			setHitPoints(0);
		} else {
			setHitPoints(getHitPoints() - amount);
		}
	}
	else {
		std::cout << "ClapTrap " << getName();
		std::cout << " is out of service!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (getEnergyPoints() > 0 && getHitPoints() > 0) {
		std::cout << "ClapTrap " << getName();
		std::cout << " got repaired by " << amount;
		std::cout << " hit points!" << std::endl;
		setHitPoints(getHitPoints() + amount);
		setEnergyPoints(getEnergyPoints() - 1);
	}
	else {
		std::cout << "ClapTrap " << getName();
		std::cout << " is out of service!" << std::endl;
	}
}

const std::string& ClapTrap::getName() const {
    return this->_name;
}

unsigned int	ClapTrap::getAttackDamage( void ) const {
	return _attackDamage;
}

unsigned int	ClapTrap::getEnergyPoints( void ) const {
	return _energyPoints;
}
unsigned int	ClapTrap::getHitPoints( void ) const {
	return _hitPoints;
}

void	ClapTrap::setEnergyPoints(unsigned int amount) {
	_energyPoints = amount;
}

void	ClapTrap::setHitPoints(unsigned int amount) {
	_hitPoints = amount;
}

void	ClapTrap::setAttackDamage(unsigned int amount) {
	_attackDamage = amount;
}

void	ClapTrap::setName(const std::string& name) {
	_name = name;
}
