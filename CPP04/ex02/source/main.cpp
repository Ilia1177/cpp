#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongCat.hpp>

int main( void ) {
	const int size = 1;

	Dog basic;
    {
        Dog tmp = basic;
    }
    Cat basic2;
    {
        Cat tmp;
        tmp = basic2;
    }

	Cat	felix;
	Cat tom;

	felix.setIdea("this is felix's idea !", 0);
	std::cout << std::endl << "felix's idea -> " << felix.getIdea(0) << std::endl;
	felix.setIdea("this is tom's idea !", 0);
	tom = felix;
	std::cout << "but tom has been cheating on felix..." << std::endl;
	std::cout << "tom's idea -> " << tom.getIdea(0) << std::endl;
	
	std::cout << std::endl << "Array of animals: " << std::endl << std::endl;
	Animal *animals[size];
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
