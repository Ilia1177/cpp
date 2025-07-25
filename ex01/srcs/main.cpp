#include "Serializer.hpp"

int main() {

	Data elementA;
	Data* elementB;
	uintptr_t ptr;

	elementA.value = 42;
	elementA.str = "This is first test";

	std::cout << "element A: " << std::endl;
	std::cout << "addr: " << &elementA << std::endl;
	std::cout << "value: " << elementA.value << std::endl;
	std::cout << "str: " << elementA.str << std::endl << std::endl;

	ptr = Serializer::serialize(&elementA);
	std::cout << "value of ptr: " << ptr << std::endl << std::endl;

	elementB = Serializer::deserialize(ptr);
	std::cout << "element B: " << std::endl;
	std::cout << "addr: " << elementB << std::endl;
	std::cout << "value: " << elementB->value << std::endl;
	std::cout << "str: " << elementB->str << std::endl << std::endl;

	return 0;
}
