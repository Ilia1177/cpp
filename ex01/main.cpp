#include "ScavTrap.hpp"

int main( void ) {
	ScavTrap Ourki("ourki");
	ClapTrap hugo("Hugo");

	hugo.attack("Jeannot");
	Ourki.guardGate();
	Ourki.attack("Nothing");
//	Jeanne.beRepaired(10);
//	hugo.takeDamage(1);
//	Graok.takeDamage(50);
//	hugo.takeDamage(1080);
//	hugo.attack("bertrand");
	return 0;
}
