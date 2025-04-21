#include "Zombie.hpp"

Zombie::Zombie() {
	_name = "unnamed";
	std::cout << "a new zombie with no name came in" << std::endl;
}

void		Zombie::setName(std::string& name) {
	_name = name;
}

std::string	Zombie::getName(void) const {
	return (_name);
}

void	Zombie::announce(void) const {
	std::cout << Zombie::getName() << ANNOUNCE << std::endl;
}

Zombie::~Zombie() {
    std::cout << _name << " has been destroyed 💀" << std::endl;
}
