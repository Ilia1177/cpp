#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
	Zombie *newBorn = new Zombie(name);
	return (newBorn);
}
