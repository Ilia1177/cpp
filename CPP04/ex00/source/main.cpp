#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongCat.hpp>

int main( void ) {
	Animal simpleInstance;
	const Animal* meta = new Animal();
	const Animal* douglas = new Dog();
	const WrongAnimal* wrong_ani_felix = new WrongCat();
	const WrongCat* wrong_cat_tom = new WrongCat();
	const Cat felix;

	std::cout << std::endl << "wrong felix (WrongAnimal) makes this noise: ";
	wrong_ani_felix->makeSound();
	std::cout << std::endl << "wrong tom (WrongCat) makes this noise: ";
	wrong_cat_tom->makeSound();
	std::cout << "douglas (Dog) makes this noise :";
	douglas->makeSound();
	std::cout << "meta (Animal) makes this noise :";
	meta->makeSound();
	std::cout << "felix (Cat) makes this noise :";
	felix.makeSound();

	delete wrong_cat_tom;
	delete wrong_ani_felix;
	delete meta;
	delete douglas;
}
