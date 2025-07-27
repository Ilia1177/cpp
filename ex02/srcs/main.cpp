#include "Array.hpp"
#include <exception>

int main() {
	int * a = new int();
	std::cout << *a << std::endl;
	
	delete a;
	{
		std::cout << "empty array" << std::endl;
		const Array<int> *arr = new Array<int>();
		std::cout << *arr << std::endl;
		delete arr;
	}
	{
		Array<int> *arr = new Array<int>(5);

		std::cout << "Int Array:" << std::endl;
		try {
			std::cout << *arr << std::endl;
			(*arr)[0] = 48;
			(*arr)[1] = 49;
			(*arr)[2] = 50;
			std::cout << *arr << std::endl;
			(*arr)[20] = 20;
		} catch (std::exception &e) {
			std::cout << "exception caugth: " << e.what() << std::endl;
		}
		delete arr;
	}
	{
		Array<char> *arr = new Array<char>(5);

		std::cout << "Char Array:" << std::endl;
		try {
			std::cout << *arr << std::endl;
			(*arr)[0] = 48;
			(*arr)[1] = 49;
			(*arr)[2] = 50;
			std::cout << *arr << std::endl;
			(*arr)[20] = 20;
		} catch (std::exception &e) {
			std::cout << "exception caugth: " << e.what() << std::endl;
		}
		delete arr;
	}
	{
		Array<float> *arr = new Array<float>(5);

		std::cout << "float Array:" << std::endl;
		try {
			std::cout << *arr << std::endl;
			(*arr)[0] = 48.98f;
			(*arr)[1] = 49.54f;
			(*arr)[2] = 50;
			std::cout << *arr << std::endl;
			(*arr)[20] = 20;
		} catch (std::exception &e) {
			std::cout << "exception caugth: " << e.what() << std::endl;
		}
		delete arr;
	}


	{
		Array<double> *arr = new Array<double>(5);

		std::cout << "Double Array:" << std::endl;
		try {
			std::cout << *arr << std::endl;
			(*arr)[0] = 48.98;
			(*arr)[1] = 49.54;
			(*arr)[2] = 50.2;
			std::cout << *arr << std::endl;
			(*arr)[20] = 20;
		} catch (std::exception &e) {
			std::cout << "exception caugth: " << e.what() << std::endl;
		}
		delete arr;
	}

	{
		Array<bool> *arr = new Array<bool>(5);

		std::cout << "Bool Array:" << std::endl;
		try {
			std::cout << *arr << std::endl;
			(*arr)[0] = false;
			(*arr)[1] = true;
			(*arr)[2] = 0;
			(*arr)[3] = 1;
			std::cout << *arr << std::endl;
		} catch (std::exception &e) {
			std::cout << "exception caugth: " << e.what() << std::endl;
		}
		delete arr;
	}

	{
		Array<std::string> *arr = new Array<std::string>(5);

		std::cout << "Std::string Array:" << std::endl;
		try {
			std::cout << *arr << std::endl;
			(*arr)[0] = "48 citron";
			(*arr)[1] = "49";
			(*arr)[2] = "orteils";
			std::cout << *arr << std::endl;
			(*arr)[20] = "20";
		} catch (std::exception &e) {
			std::cout << "exception caugth: " << e.what() << std::endl;
		}
		delete arr;
	}
	{
		Array<std::pair<int, std::string> > *arr = new Array<std::pair<int, std::string> >(8);

		std::cout << "Std::pair Array:" << std::endl;
		try {
			std::cout << *arr << std::endl;
			(*arr)[0] = std::make_pair(48, "citron");
			(*arr)[1] = std::make_pair(48, "citron");
			(*arr)[2] = std::make_pair(48, "citron");
			(*arr)[3] = std::make_pair(48, "citron");
			std::cout << *arr << std::endl;
		} catch (std::exception &e) {
			std::cout << "exception caugth: " << e.what() << std::endl;
		}
		delete arr;
	}

	std::cout << "stack array of int" << std::endl;
	Array<int> inStack(5);
	inStack[1] = 3;
	std::cout << inStack << std::endl;
	return 0;
}

