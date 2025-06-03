#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie *horde;
	
	if (N <= 0) {
		N = 1;
		std::cout << "Number is invalid. Horde is set to 1" << std::endl;
	}
	horde = new Zombie[N];
	for (int i = 0; i < N; ++i) {
		horde[i].announce();
	} for (int i = 0; i < N; ++i) {
		horde[i].setName(name);
		horde[i].announce();
	}
	return (horde);
}

