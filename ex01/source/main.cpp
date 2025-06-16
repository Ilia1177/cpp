#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongCat.hpp>

int main( void ) {
	const int size = 3;

	Dog basic;
    {
        Dog tmp = basic;
    }
    Cat basic2;
    {
        Cat tmp;
        tmp = basic2;
    }
	std::cout << "Stack manipulation: " << std::endl << std::endl;
	Animal a;
	Animal c;
	Cat d;

	c = d;

	std::cout << "Heap manipulation: " << std::endl << std::endl;
	Cat *e = NULL;
	Cat *f = new Cat;
	Cat g(*f);

	Animal *h;

	h = new Cat;
	e = f;
	delete f;
	delete h;

	std::cout << "Deep copy of brain: " << std::endl << std::endl;
	
	Cat	felix;
	Cat tom;

	felix.setIdea("felix's idea is great", 0);
	std::cout << std::endl << "felix: " << felix.getIdea(0) << std::endl;
	tom = felix;
	std::cout << "tom: " << tom.getIdea(0) << std::endl;
	
	felix.setIdea("finally it s not that good...", 0);
	std::cout << "felix: " << felix.getIdea(0) << std::endl;
	std::cout << "tom: " << tom.getIdea(0) << std::endl;

	Cat mauer = felix;
	std::cout << "Mauer: " << mauer.getIdea(0) << std::endl;



	std::cout << "Array of animals: " << std::endl << std::endl;
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
