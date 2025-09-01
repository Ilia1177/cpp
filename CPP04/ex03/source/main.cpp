
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int scene0() {
	AMateria *floor;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	floor = dynamic_cast<Character*>(me)->getMateria(1);
	me->unequip(1);
	delete floor;
	delete bob;
	delete me;
	delete src;
	return (0);
}

int scene1() {
		AMateria *floor;
		Character* Adobe = new Character("Adobe");
		Character* Narok = new Character("Narok");
		AMateria* tmp;
		IMateriaSource* factory = new MateriaSource();

		factory->learnMateria(new Ice());
		factory->learnMateria(new Cure());
		factory->learnMateria(NULL);

		Adobe->use(2, *Adobe);
		Adobe->equip(factory->createMateria("ice"));
		Narok->equip(factory->createMateria("cure"));
		Adobe->equip(factory->createMateria("Unknown materia"));
		Adobe->equip(factory->createMateria("cure"));
		Adobe->equip(factory->createMateria("ice"));
		Adobe->equip(factory->createMateria("cure"));
		tmp = factory->createMateria("cure");
		Adobe->equip(tmp);
		delete tmp;
		Narok->printInventory();
		Adobe->printInventory();
		std::cout << "Cloning characters..." << std::endl;
		*Narok = *Adobe;
		Narok->printInventory();
		Adobe->printInventory();
		Narok->use(0, *Adobe);
		Narok->use(1, *Adobe);
		Narok->use(2, *Adobe);
		Narok->use(3, *Adobe);
		floor = dynamic_cast<Character*>(Narok)->getMateria(0);
		Narok->unequip(0);
		delete floor;
		delete factory;
		delete Adobe;
		delete Narok;
		return (0);
}

int main()
{
	scene0();
	scene1();

	return (0);
}
