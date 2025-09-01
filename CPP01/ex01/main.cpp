#include "Zombie.hpp"

int	main(int ac, char** av) {

	Zombie		*zombies;
	int			number;

	zombies = NULL;
	number = 0;
	if (ac > 1) {
		std::stringstream ss(av[1]);
		ss >> number;
		if (ss.fail()) {
			std::cout << "Invalid number!" << std::endl;
			return (1);
		}
	}
	if (number > 0 && number < 1000) {
		zombies = zombieHorde(number, "Zonzon");
	} else {
		std::cout << "enter a number of zombies between 1 and 999";
		return (1);
	}
	if (zombies)
		delete[] zombies;
}
