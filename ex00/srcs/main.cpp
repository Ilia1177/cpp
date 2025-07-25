#include "templates.hpp"

int main() {
	{
		int a = 1;
		int b = 3;

		std::cout << std::endl << "Integer" << std::endl;
		std::cout << "a: " << a << ", b: " << b << std::endl;
		::swap(a, b);
		std::cout << "a: " << a << ", b: " << b << std::endl;
		std::cout << "min: " << ::min(a, b) << std::endl;
		std::cout << "max: " << ::max(a, b) << std::endl;
	}

	{
		float a = 1.6f;
		float b = 5.99f;

		std::cout << std::endl << "Floating point" << std::endl;
		std::cout << "a: " << a << ", b: " << b << std::endl;
		::swap(a, b);
		std::cout << "a: " << a << ", b: " << b << std::endl;
		std::cout << "min: " << ::min(a, b) << std::endl;
		std::cout << "max: " << ::max(a, b) << std::endl;
	}
	{
		double a = 51.688;
		double b = 99.99;

		std::cout << std::endl << "Double" << std::endl;
		std::cout << "a: " << a << ", b: " << b << std::endl;
		::swap(a, b);

		std::cout << "a: " << a << ", b: " << b << std::endl;
		std::cout << "min: " << ::min(a, b) << std::endl;
		std::cout << "max: " << ::max(a, b) << std::endl;
	}
	{
		unsigned int a = 51688;
		unsigned int b = 9999;

		std::cout << std::endl << "Unsigned int" << std::endl;
		std::cout << "a: " << a << ", b: " << b << std::endl;
		::swap(a, b);

		std::cout << "a: " << a << ", b: " << b << std::endl;
		std::cout << "min: " << ::min(a, b) << std::endl;
		std::cout << "max: " << ::max(a, b) << std::endl;
	}
	{
		unsigned short a = 51688;
		unsigned short b = 9999;

		std::cout << std::endl << "Unsigned short" << std::endl;
		std::cout << "a: " << a << ", b: " << b << std::endl;
		::swap(a, b);

		std::cout << "a: " << a << ", b: " << b << std::endl;
		std::cout << "min: " << ::min(a, b) << std::endl;
		std::cout << "max: " << ::max(a, b) << std::endl;
	}
	{
		wchar_t a = 'q';
		wchar_t b = 'Q';

		std::cout << std::endl << "wchar_t" << std::endl;
		std::cout << "a: " << a << ", b: " << b << std::endl;
		::swap(a, b);

		std::cout << "a: " << a << ", b: " << b << std::endl;
		std::cout << "min: " << ::min(a, b) << std::endl;
		std::cout << "max: " << ::max(a, b) << std::endl;
	}
	{
		std::string a = "vin rouge";
		std::string b = "omelette";

		std::cout << std::endl << "std::string" << std::endl;
		std::cout << "a: " << a << ", b: " << b << std::endl;
		::swap(a, b);

		std::cout << "a: " << a << ", b: " << b << std::endl;
		std::cout << "min: " << ::min(a, b) << std::endl;
		std::cout << "max: " << ::max(a, b) << std::endl;
	}
	return 0;
}
