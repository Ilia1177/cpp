#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongCat.hpp>

int main( void ) {
//	const Animal* meta = new Animal();
	const Animal* a = new Dog();
	Dog	*b = new Dog();

	a->setIdea("nouvelle idee", 1);
	b = a;
	std::cout << "idea from A: " << a->getIdea(1) << std::endl;
	std::cout << "Idea from B: " << b->getIdea(1) << std::endl;
	b->setIdea("old Idea", 1);

	std::cout << "idea from A: " << a->getIdea(1) << std::endl;
	std::cout << "Idea from B: " << b->getIdea(1) << std::endl;
	a->makeSound();

	delete a;
	delete b;
}
