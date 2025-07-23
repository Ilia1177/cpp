#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <cerrno>
# include <climits>

//enum e_type {
//	CHAR = 0,
//	INT = 1,
//	FLOAT = 2,
//	DOUBLE = 3,
//	INFINITE = 4,
//	FAULT = -1
//};

class ScalarConverter
{
	public:
		static void convert(const std::string& str);
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
};

bool	isInt(const std::string& str);
bool	isFloat(const std::string& str);
bool	isDouble(const std::string& str);
bool	isInfinite(const std::string& str);
bool	notANumber(const std::string& str);

int		convertToInt(const std::string& str);
char	convertToChar(const std::string& str);
float	convertToFloat(const std::string& str);
double	convertToDouble(const std::string& str);
#endif

