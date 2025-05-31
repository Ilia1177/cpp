#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongCat.hpp>

int main( void ) {
	const int size = 3;

	Animal *animals[size];
	
	Cat	felix;
	Cat tom;

	Animal a;

	felix.setIdea("felix's idea is great", 0);
	std::cout << std::endl << "felix: " << felix.getIdea(0) << std::endl;
	tom = felix;
	std::cout << "tom: " << tom.getIdea(0) << std::endl;
	
	for (int i = 0; i < size; ++i) {
		if (i % 2 == 0)
			animals[i] = new Dog;
		else
		 	animals[i] = new Cat;
	}

	for (int i = 0; i < size; ++i) {
		delete animals[i];
	}
}
