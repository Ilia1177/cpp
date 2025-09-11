#include "ScalarConverter.hpp"

// Default constructor
ScalarConverter::ScalarConverter(void) {}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void) other;}

// Assignment operator overload
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {(void) other; return (*this);}

// Destructor
ScalarConverter::~ScalarConverter(void) {}

void ScalarConverter::convert(const std::string& str) {

	try {
		std::cout << "char: ";
		char charValue = convertToChar(str);
		std::cout << "'" << charValue << "'" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "int: ";
		int intValue = convertToInt(str);
		std::cout << intValue << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "float: ";
		float floatValue = convertToFloat(str);
		std::cout << std::fixed << floatValue << "f" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "double: ";
		double doubleValue = convertToDouble(str);
		std::cout << std::fixed << doubleValue  << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
