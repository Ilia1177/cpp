#include "Zombie.hpp"

std::string	Zombie::getName(void) const {
	return (_name);
}

void	Zombie::announce(void) const {
	std::cout << Zombie::getName() << ANNOUNCE << std::endl;
}

Zombie::~Zombie() {
    std::cout << _name << " has been destroyed 💀" << std::endl;
}
