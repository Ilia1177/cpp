#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongCat.hpp>

int main( void ) {
	const Animal* meta = new Animal();
	const Animal* douglas = new Dog();
	const WrongAnimal* wrong = new WrongCat();
	const Cat felix;

	std::cout << std::endl << "wrong (WrongCat) makes this noise: ";
	wrong->makeSound();
	std::cout << "douglas (Dog) makes this noise :";
	douglas->makeSound();
	std::cout << "meta (Animal) makes this noise :";
	meta->makeSound();
	std::cout << "felix (Cat) makes this noise :";
	felix.makeSound();
	delete meta;
	delete douglas;
	delete wrong;
}
