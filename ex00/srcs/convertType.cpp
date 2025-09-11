#include "ScalarConverter.hpp"
#include "ImpossibleConversion.hpp"
#include <iostream>

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
	if (str[i++] != '.')
		return false;
	for (; i < ft_strlen(str) && str[i] != 'f'; i++) {
		if (!isDigit(str[i]))
			return false;
	}
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

// converting function //
int convertToInt(const std::string& str)
{
    char cstr[20];
    char* endptr = NULL;
	bool floatSign = false;

    errno = 0;
	if (::isChar(str)) 
		return static_cast<int>(str[1]);
	ft_c_str(str, cstr, 20);
    long value = std::strtol(cstr, &endptr, 10);

    if (errno == ERANGE || value < INT_MIN || value > INT_MAX) {
        throw ImpossibleConversion();
    } else if (*endptr != '\0' && *endptr != '.') {
		throw ImpossibleConversion();
	} else if (*endptr == '.') {
		for (size_t i = 1; i < ft_strlen(endptr); i++) {
			if (endptr[i] == 'f' && floatSign == false) {
				floatSign = true;
			} else if (endptr[i] == 'f' && floatSign == true) {
				throw ImpossibleConversion();
			} else if (!::isDigit(endptr[i])) {
				throw ImpossibleConversion();
			}
		}
		if (ft_strlen(endptr) == 1 && cstr - endptr == 0)
			throw ImpossibleConversion();
	}
    return static_cast<int>(value);
}

char convertToChar(const std::string& str)
{
	if (::isChar(str))
		return static_cast<char>(str[1]);
	try {
		int value = convertToInt(str);
		if (value >= 32 && value <= 126) {
			return static_cast<char>(value);
		} else if (value <= 127 && value >= 0){
			throw std::invalid_argument("Non displayable");
		} else {
			throw ImpossibleConversion();
		}
	} catch (...) {
		throw ;
	}
}

float convertToFloat(const std::string& str)
{
	char *endptr = NULL;
	char cstr[256];
	errno = 0;
	if (::isChar(str)) {
		return static_cast<float>(str[1]);
	}
	ft_c_str(str, cstr, 256);
    if (notANumber(str)) {
        return getNaNf();
    }
	float floatValue =  std::strtof(cstr, &endptr);
	if (errno == ERANGE)
		throw std::invalid_argument("float overflow (impossible conversion: +-inf)");
	else if (endptr == cstr)
		throw ImpossibleConversion();
	return floatValue;
}

double convertToDouble(const std::string& str)
{
	char cstr[256];
	char *endptr;
	errno = 0;

	if (isChar(str))
		return static_cast<double>(str[1]);
	if (notANumber(str)) {
        return getNaNd();
    }
	if (ft_strlen(str) > 256)
		throw std::invalid_argument("String is too long (either overflow or too much precision) for this exercice. Be a reasonable person.");
	ft_c_str(str, cstr, 256);
	double doubleValue =  std::strtod(cstr, &endptr);
	if (errno == ERANGE || cstr == endptr)
		throw ImpossibleConversion();
	return doubleValue;
}

