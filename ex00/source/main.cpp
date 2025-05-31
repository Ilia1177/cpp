#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongCat.hpp>

int main( void ) {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const WrongAnimal* i = new WrongCat();
	const Dog doggy;

	std::cout << "type of j is: " << j->getType() << " " << std::endl;
	std::cout << "type of i is: " << i->getType() << " " << std::endl;
	std::cout << "i makes sound :" << std::endl;
	i->makeSound();
	std::cout << "j makes sound :" << std::endl;
	j->makeSound();
	meta->makeSound();
	std::cout << "doggy makes sound :" << std::endl;
	doggy.makeSound();
	delete meta;
	delete j;
	delete i;
}
