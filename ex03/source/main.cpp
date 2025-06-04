
#include <Ice.hpp>
#include <Cure.hpp>
#include <Character.hpp>
#include "MateriaSource.hpp"

int main()
{
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
}
