#include "Zombie.hpp"

int	main(int ac, char** av) {

	Zombie		*zombie;
	std::string	name;

	zombie = NULL;
	if (ac >= 2) {
		zombie = newZombie(av[1]);
		zombie->announce();
	} else if (ac < 2) {
		std::cout << "enter zombie name: ";
		std::getline(std::cin, name);
		zombie = newZombie(name);
		zombie->announce();
	}
	randomChump("ghost");
	if (zombie)
		zombie->announce();
	if (zombie)
		delete zombie;
}
