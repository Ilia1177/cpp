#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongCat.hpp>

int main( void ) {
	const int size = 6;

	Animal *animals[size];

	for (int i = 0; i < size; ++i) {
		if (i % 2 == 0)
			animals[i] = new Dog;
		else
		 	animals[i] = new Cat;
	}

	animals[1]->setIdea("cool Idea", 1);
	std::cout << animals[1]->getIdea(1) << std::endl;
	animals[1]->setIdea("not cool anymore", 1);
	std::cout << animals[1]->getIdea(1) << std::endl;
	std::cout << animals[1]->getIdea(0) << std::endl;
	for (int i = 0; i < size; ++i) {
		delete animals[i];
	}
}
