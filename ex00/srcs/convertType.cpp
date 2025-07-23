#include "ScalarConverter.hpp"
#include <cinttypes>
#include <iostream>

e_type getType(const std::string& str) {
	if (isInt(str)) {
		return (INT);
	} else if (isFloat(str)) {
		return (FLOAT);
	} else if (isDouble(str)) {
		return (DOUBLE);
	} else if (isInfinite(str)) {
		return (INFINITE);
	} else if (isChar(str)) {
		return (CHAR);
	}
	return(FAULT);
}

bool isDigit(int c) {
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

bool isInt(const std::string& str) {

	size_t i = 0;

	if (str.length() == 0)
		return false;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < str.length()) {
		if (!isDigit(str[i]))
			return false;
		i++;
	}
	return true;
}

bool isChar(const std::string& str)
{
	if (str.length() != 1)
		return false;
	if (str[0] >= 32 && str[0] <= 127)
		return true;
	return false;
}

bool isFloat(const std::string& str)
{
	size_t i = 0;

	if (str.length() == 0)
		return false;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < str.length() && str[i] != '.') {
		if (!isDigit(str[i]))
			return false;
		i++;
	}
	if (str[i] != '.')
		return false;
	i++;
	while (i < str.length() && str[i] != 'f') {
		if (!isDigit(str[i]))
			return false;
		i++;
	}
	if (str[i] != 'f' || i + 1 != str.length())
		return false;
	return true;
}

bool isDouble(const std::string& str)
{
	size_t i = 0;

	if (str.length() == 0)
		return false;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < str.length() && str[i] != '.') {
		if (!isDigit(str[i]))
			return false;
		i++;
	}
	if (str[i] != '.')
		return false;
	i++;
	while (i < str.length()) {
		if (!isDigit(str[i]))
			return false;
		i++;
	}
	return true;
}

bool isInfinite(const std::string& str)
{
	if (str == "+inff" || str == "-inff")
		return true;
	if (str == "+inf" || str == "-inf")
		return true;
	return false;
}

int convertToInt(const std::string& str) {
	
	errno = 0;
	long value = std::strtol(str.c_str(), nullptr, 10);

	if (errno == ERANGE || value > INT_MAX || value < INT_MIN) {
		std::cout << "impossible conversion" << std::endl;
		throw "overflow";
	} 
	int intValue = static_cast<int>(value);
	return intValue;
	//std::cout << "int: " << intValue << std::endl;
}

void convertToChar(const std::string& str) {

	(void)str;
	//std::cout << str[0] << std::endl;
}

float convertToFloat(const std::string& str) {

	errno = 0;
	char* endptr;
	float value = std::strtof(str.c_str(), &endptr);

	if (errno == ERANGE) {
		if (value == HUGE_VALF) {
			return +INFF;
		} else if (value == -HUGE_VALF) {
			return -INFF;
		}// else if (value == 0.0f) {
		//	throw "impossible";
		//}
	} else if (std::isnan(value)) {
		throw "nan";
	}
	return value;
}

void printDouble(const std::string& str) {

	errno = 0;
	char* endptr;
	double value = std::strtod(str.c_str(), &endptr);

	if (errno == ERANGE) {
		if (value == HUGE_VALF) {
			std::cout << "float: +inf" << std::endl;
		} else if (value == -HUGE_VALF) {
			std::cout << "float: -inf" << std::endl;
		} else if (value == 0.0) {
			std::cout << "float: underflow" << std::endl;
		}
	} else if (std::isinf(value)) {
		std::cout << "float: +inf or -inf" << std::endl;
	} else if (std::isnan(value)) {
		std::cout << "float: nan" << std::endl;
	} else {
		std::cout << "float: " << value << std::endl;
	}
}


