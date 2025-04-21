#include "Zombie.hpp"

int	main(int ac, char** av) {

	Zombie		*zombies;
	int			number;

	zombies = NULL;
	number = 0;
	if (ac > 1)
		number = std::atoi(av[1]);
	if (number > 0) {
		zombies = zombieHorde(number, "Zonzon");
	} else if (number <= 0 || number > 1000) {
		std::cout << "enter a number of zombies between 1 and 1000";
		return (1);
	}
	if (zombies)
		delete[] zombies;
}
