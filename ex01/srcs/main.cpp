#include "Serializer.hpp"

int main() {

	Data elementA("FIRST test", 42);
	Data* elementB;
	uintptr_t ptr;

	std::cout << "element A: " << std::endl;
	std::cout << "     addr: " << &elementA << std::endl;
	std::cout << "    value: " << elementA.value << std::endl;
	std::cout << "      str: " << elementA.str << std::endl << std::endl;

	std::cout << "- serialisation -" << std::endl;
	ptr = Serializer::serialize(&elementA);
	std::cout << "value of ptr: " << ptr << std::endl << std::endl;

	std::cout << "- deserialisation -" << std::endl;
	elementB = Serializer::deserialize(ptr);
	std::cout << "element B: " << std::endl;
	std::cout << "     addr: " << elementB << std::endl;
	std::cout << "    value: " << elementB->value << std::endl;
	std::cout << "      str: " << elementB->str << std::endl << std::endl;

	return 0;
}
