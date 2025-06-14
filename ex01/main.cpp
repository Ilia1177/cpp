#include "ScavTrap.hpp"

int main( void ) {
	ScavTrap ourki("ourki");
	ClapTrap hugo("Hugo");

	std::cout << "hugo hit points: " << hugo.getHitPoints() << std::endl;
	std::cout << "hugo energy points: " << hugo.getEnergyPoints() << std::endl;
	std::cout << "hugo attack damage: " << hugo.getAttackDamage() << std::endl;

	std::cout << "Ourki hit points: " << ourki.getHitPoints() << std::endl;
	std::cout << "Ourki energy points: " << ourki.getEnergyPoints() << std::endl;
	std::cout << "Ourki attack damage: " << ourki.getAttackDamage() << std::endl;
	hugo.attack("Ourki");
	ourki.takeDamage(3);
	ourki.guardGate();
	ourki.attack("Nothing");
	hugo.beRepaired(2);
//	hugo.guardGate();
	ourki.beRepaired(10);
	hugo.attack("Ourki");
	ourki.takeDamage(50);
	ourki.attack("Hugo");
	hugo.takeDamage(1080);
	hugo.beRepaired(30);
	hugo.attack("SHOULD NOT BE OUTPUT");
	hugo.takeDamage(30);
	hugo.getHitPoints();
	hugo.getAttackDamage();
	hugo.getEnergyPoints();


	std::cout << "hugo hit points: " << hugo.getHitPoints() << std::endl;
	std::cout << "hugo energy points: " << hugo.getEnergyPoints() << std::endl;
	std::cout << "hugo attack damage: " << hugo.getAttackDamage() << std::endl;

	std::cout << "Ourki hit points: " << ourki.getHitPoints() << std::endl;
	std::cout << "Ourki energy points: " << ourki.getEnergyPoints() << std::endl;
	std::cout << "Ourki attack damage: " << ourki.getAttackDamage() << std::endl;
//	hugo.attack("bertrand");
	return 0;
}
