#include "DiamondTrap.hpp"

int main( void ) {
	DiamondTrap jp = DiamondTrap("Jean-Pierre");
	
	ScavTrap scav = ScavTrap("skarlatine");
	ClapTrap clap("clapinette");
	FragTrap frag("Frangipane");

	FragTrap copy_frag;
	ScavTrap copy_scav;
	ClapTrap copy_clap;
	DiamondTrap	copy_diamond;

	std::cout << "COPY START" << std::endl;
	copy_frag = frag;
	std::cout << "COPY END" << std::endl;
	copy_clap = clap;
	copy_scav = scav;
	copy_diamond = jp;

	std::cout << "Frag  hit points   : " << frag.getHitPoints() << std::endl;
	std::cout << "Frag  energy points: " << frag.getEnergyPoints() << std::endl;
	std::cout << "Frag  attack damage: " << frag.getAttackDamage() << std::endl;

	std::cout << "copy_Frag  hit points   : " << copy_frag.getHitPoints() << std::endl;
	std::cout << "copy_Frag  energy points: " << copy_frag.getEnergyPoints() << std::endl;
	std::cout << "copy_Frag  attack damage: " << copy_frag.getAttackDamage() << std::endl;
	std::cout << copy_frag.getName() << std::endl;

	std::cout << "scav hit points   : " << scav.getHitPoints() << std::endl;
	std::cout << "scav energy points: " << scav.getEnergyPoints() << std::endl;
	std::cout << "scav attack damage: " << scav.getAttackDamage() << std::endl;

	std::cout << "clap hit points   : " << clap.getHitPoints() << std::endl;
	std::cout << "clap energy points: " << clap.getEnergyPoints() << std::endl;
	std::cout << "clap attack damage: " << clap.getAttackDamage() << std::endl;
	jp.attack("Bruel");
	frag.takeDamage(80);
	scav.beRepaired(40);
	scav.guardGate();
	clap.takeDamage(35);
	jp.whoAmI();
	copy_diamond.whoAmI();
	jp.guardGate();
	jp.highFivesGuys();
	std::cout << "clap hit points   : " << clap.getHitPoints() << std::endl;
	std::cout << "clap energy points: " << clap.getEnergyPoints() << std::endl;
	std::cout << "clap attack damage: " << clap.getAttackDamage() << std::endl;
	return 0;
}
