#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap hugo("Hugo");
	ClapTrap Jeanne("Jeanne");

	hugo.attack("Jeano");
	Jeanne.beRepaired(10);
	hugo.takeDamage(1);
	hugo.beRepaired(2);
	hugo.takeDamage(9);
	hugo.attack("bertrand");
	hugo.takeDamage(40);
	hugo.takeDamage(40);
	return 0;
}
