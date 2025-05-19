#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap(void): {
    std::cout << "An unknown DiamonTrap has arrived" << std::endl;
    return ;
}

// Copy constructor
DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name) {
    std::cout << "DiamondTrap " << getName() << " has arrived!" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
DiamondTrap::~DiamondTrap(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

