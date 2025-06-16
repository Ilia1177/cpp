#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
	ScavTrap ourki("ourki");
	ClapTrap hugo("Hugo");

	FragTrap jeanLouis("loulou");

	return (0);
	std::cout << "Clap hugo hit points: " << hugo.getHitPoints() << std::endl;
	std::cout << "Clap hugo energy points: " << hugo.getEnergyPoints() << std::endl;
	std::cout << "Clap hugo attack damage: " << hugo.getAttackDamage() << std::endl;

	std::cout << "Scav Ourki hit points: " << ourki.getHitPoints() << std::endl;
	std::cout << "Scav Ourki energy points: " << ourki.getEnergyPoints() << std::endl;
	std::cout << "Scav Ourki attack damage: " << ourki.getAttackDamage() << std::endl;

	std::cout << "Frag JeanLouis hit points: " << jeanLouis.getHitPoints() << std::endl;
	std::cout << "Frag JeanLouis energy points: " << jeanLouis.getEnergyPoints() << std::endl;
	std::cout << "Frag JeanLouis attack damage: " << jeanLouis.getAttackDamage() << std::endl;

	hugo.beRepaired(10);
	hugo.attack("Jeannot");

	ourki.guardGate();
	ourki.attack("Nothing");

	jeanLouis.takeDamage(20);
	jeanLouis.highFivesGuys();
//	jeanLouis.guardGate(); no exist
	jeanLouis.attack("ourki");
	ourki.takeDamage(1080);
	ourki.beRepaired(10000);


//	Jeanne.beRepaired(10);
//	hugo.takeDamage(1);
//	Graok.takeDamage(50);
//	hugo.takeDamage(1080);
//	hugo.attack("bertrand");
	return 0;
}
