#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
	ScavTrap Ourki("ourki");
	ClapTrap hugo("Hugo");

	FragTrap jeanLouis("loulou");

	hugo.attack("Jeannot");
	Ourki.guardGate();
	Ourki.attack("Nothing");
	jeanLouis.takeDamage(9999999);
	jeanLouis.highFivesGuys();
//	Jeanne.beRepaired(10);
//	hugo.takeDamage(1);
//	Graok.takeDamage(50);
//	hugo.takeDamage(1080);
//	hugo.attack("bertrand");
	return 0;
}
