#include "ScalarConverter.hpp"
#include "ImpossibleConversion.hpp"
#include <cinttypes>
#include <iostream>

//e_type getType(const std::string& str) {
//	if (isInt(str)) {
//		return (INT);
//	} else if (isFloat(str)) {
//		return (FLOAT);
//	} else if (isDouble(str)) {
//		return (DOUBLE);
//	} else if (isInfinite(str)) {
//		return (INFINITE);
//	} else if (isChar(str)) {
//		return (CHAR);
//	}
//	return(FAULT);
//}

size_t ft_strlen(const std::string& str)
{
	size_t len;
	for (len = 0; str[len] != 0; len++);
	return len;
}

bool isDigit(int c) {
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

bool isChar(const std::string& str) {
	if (ft_strlen(str) != 3) {
		return false;
	} else if (str[0] != '\'' || str[2] != '\'') {
		return false;
	} else if (str[1] < 32 || str[1] > 126) {
		return false;
	}
	return true;
}

bool isInt(const std::string& str) {

	size_t i = 0;

	if (ft_strlen(str) == 0)
		return false;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < ft_strlen(str)) {
		if (!isDigit(str[i]))
			return false;
		i++;
	}
	return true;
}

bool isFloat(const std::string& str)
{
	size_t i = 0;

	if (str == "inff" || str == "-inff" || str == "+inff")
		return true;
	if (str.length() == 0)
		return false;
	if (str[i] == '-' || str[i] == '+')
		i++;
	for (; i < ft_strlen(str) && str[i] != '.'; i++) {
		if (!isDigit(str[i]))
			return false;
	}
//	while (i < ft_strlen(str) && str[i] != '.') {
//		if (!isDigit(str[i]))
//			return false;
//		i++;
//	}
	if (str[i++] != '.')
		return false;
	for (; i < ft_strlen(str) && str[i] != 'f'; i++) {
		if (!isDigit(str[i]))
			return false;
	}
//	while (i < ft_strlen(str) && str[i] != 'f') {
//		if (!isDigit(str[i]))
//			return false;
//		i++;
//	}
	if (str[i++] != 'f' || i != ft_strlen(str))
		return false;
	return true;
}

bool isDouble(const std::string& str)
{
	size_t i = 0;

	if (str == "inf" || str == "-inf" || str == "+inf")
		return true;
	if (ft_strlen(str) == 0)
		return false;
	if (str[i] == '-' || str[i] == '+')
		i++;
	for (; i < ft_strlen(str) && str[i] != '.'; i++) {
		if (!isDigit(str[i]))
			return false;
	}
	if (str[i++] != '.')
		return false;
	for (; i < ft_strlen(str); i++) {
		if (!isDigit(str[i]))
			return false;
	}
	return true;
}


int convertToInt(const std::string& str)
{
	if (isChar(str))
		return static_cast<int>(str[1]);
    try {
        int value = std::stoi(str);  // Direct conversion to int
        return value;
    } catch (...) {
        throw ImpossibleConversion();
    }
}

char convertToChar(const std::string& str)
{
	if (isChar(str))
		return static_cast<char>(str[1]);
	if (!isInt(str))
		throw ImpossibleConversion();
	try {
		int value = convertToInt(str);
		if (value >= 32 && value <= 126)
			return static_cast<char>(value);
		else {
			throw ImpossibleConversion();
		}
	} catch (...) {
		throw ImpossibleConversion();
	}
}

float convertToFloat(const std::string& str) {
	if (isChar(str)) {
		return static_cast<float>(str[1]);
	}
    if (notANumber(str)) {
        return NAN;
    }
	try {
		float floatValue =  std::stof(str);
		return floatValue;
	} catch (...) {
		throw ImpossibleConversion();
	}
}

double convertToDouble(const std::string& str)
{
	if (isChar(str)) {
		return static_cast<double>(str[1]);
	} else if (notANumber(str)) {
        return NAN;
    }
	try {
		double doubleValue =  std::stod(str);
		return doubleValue;
	} catch (...) {
		throw ImpossibleConversion();
	}
}

bool	notANumber(const std::string& str) {
	if (!isInt(str) && !isDouble(str) && !isFloat(str))
		return true;
	return false;
}
