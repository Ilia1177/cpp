#include "iter.hpp"

template<typename T>
void increment(T &obj) {
	obj++;
}

template<typename T>
void print(const T &obj) {
	std::cout << obj << " ";
}

int main() {
	size_t len = 10;
	{
		std::cout << "Int array" << std::endl;
		int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

		iter(arr, len, &print);
		std::cout <<  std::endl;
		iter(arr, len, &increment);
		iter(arr, len, &print);
		std::cout << std::endl << std::endl;
	}
	{
		std::cout << "CONST Char array" << std::endl;
		const char arr[] = {'r', 'd', 'w', 48, 'H', '$', '%', '(', ':', 'A'};

		iter(arr, 10, &print);
		std::cout <<  std::endl;
		iter(arr, 10, &print);
		std::cout <<  std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "std::string" << std::endl;
		std::string arr = "10 chars string";

		iter(&arr[0], arr.length(), print);
		std::cout <<  std::endl;
		iter(&arr[0], arr.length(), &increment);

		iter(&arr[0], arr.length(), print);
		std::cout << std::endl;
	}
	return 0;
}
