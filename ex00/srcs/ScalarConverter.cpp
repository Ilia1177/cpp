#include "ScalarConverter.hpp"

// Default constructor
ScalarConverter::ScalarConverter(void) {
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    std::cout << "Copy constructor called" << std::endl;
	*this = other;
    return ;
}

// Assignment operator overload
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
ScalarConverter::~ScalarConverter(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

void ScalarConverter::convert(const std::string& str) {

	try {
		std::cout << "char: ";
		char charValue = convertToChar(str);
		std::cout << "'" << charValue << "'" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Impossible conversion" << std::endl;
	}

	try {
		std::cout << "int: ";
		int intValue = convertToInt(str);
		std::cout << intValue << std::endl;
	} catch (std::exception &e) {
		std::cout << "Impossible conversion" << std::endl;
	}

	try {
		std::cout << "float: ";
		float floatValue = convertToFloat(str);
		std::cout << std::fixed << floatValue << "f" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Impossible conversion" << std::endl;
	}
	try {
		std::cout << "double: ";
		double doubleValue = convertToDouble(str);
		std::cout << std::fixed << doubleValue  << std::endl;
	} catch (std::exception &e) {
		std::cout << "Impossible conversion" << std::endl;
	}
}
