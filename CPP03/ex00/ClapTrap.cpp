#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap(void):
	_name("Unknown"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Default constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(const std::string& name):
	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other): 
	_name(other._name),
	_hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage) {
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "Assignment operator called" << std::endl;
    this->_attackDamage = other._attackDamage;
	this->_energyPoints = other._energyPoints;
	this->_hitPoints = other._hitPoints;
    return (*this);
}

// Destructor
ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

void ClapTrap::attack(const std::string& target) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		std::cout << "CalpTrap " << _name;
		std::cout << " attacks " << target << ", ";
		std::cout << " causing " << _attackDamage;
		std::cout << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else {
		std::cout << "CalpTrap " << _name;
		std::cout << " is out of service!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		std::cout << "CalpTrap " << _name;
		std::cout << " got " << amount;
		std::cout << " points of damage!" << std::endl;
		_hitPoints -= amount;
	}
	else {
		std::cout << "CalpTrap " << _name;
		std::cout << " is out of service!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		std::cout << "CalpTrap " << _name;
		std::cout << " got repaired by " << amount;
		std::cout << " points!" << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
	else {
		std::cout << "CalpTrap " << _name;
		std::cout << " is out of service!" << std::endl;
	}
}
