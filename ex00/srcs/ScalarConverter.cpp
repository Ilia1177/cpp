#include "ScalarConverter.hpp"

// Default constructor
ScalarConverter::ScalarConverter(void)
{
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
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

	//size_t len = str.length();

	e_type type = getType(str);

	try {
		printChar(str);
	} catch (const char
	printInt(str);
	printFloat(str);
	printDouble(str);

	if (type == INT) {
		//intConversion(str);
		std::cout << "Is INT !!" << std::endl;	
	} else if (type == FLOAT) {
		std::cout << "Is FLOAT !!" << std::endl;
	} else if (type == DOUBLE) {
	 	std::cout << "Is DOUBLE !!" << std::endl;
	} else if (type == INFINITE) {
	 	std::cout << "Is INFINITE !!" << std::endl;
	} else if (type == CHAR) {
	 	std::cout << "Is CHAR !! " << std::endl;
	} else if (type == FAULT) {
		std::cout << "// FAULT //" << std::endl;	
	} else {
		std::cout << "...... error" << std::endl;	
	}
}
