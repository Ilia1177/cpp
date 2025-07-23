#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
#include <cerrno>
# include <climits>

# define MIN_INT std::numeric_limits<int>::min() //-2147483648
# define MAX_INT std::numeric_limits<int>::max() //2147483647
# define MIN_FLOAT std::numeric_limits<float>::min() //-3.40282e+38
# define MAX_FLOAT std::numeric_limits<float>::max() //3.40282e+38
# define MIN_DOUBLE std::numeric_limits<double>::min() //-1.79769e+308
# define MAX_DOUBLE std::numeric_limits<double>::max() //1.79769e+308
# define INFF 		std::numeric_limits<float>::infinity();
# define INF 		std::numeric_limits<double>::infinity();
# define NANF		std::numeric_limits<float>::quiet_NaN();  // Returns NaN
# define NAND		std::numeric_limits<double>::quiet_NaN();  // Returns NaN

enum e_type {
	CHAR = 0,
	INT = 1,
	FLOAT = 2,
	DOUBLE = 3,
	INFINITE = 4,
	FAULT = -1
};

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

e_type	getType(const std::string& str);
bool	isInt(const std::string& str);
bool	isFloat(const std::string& str);
bool	isDouble(const std::string& str);
bool	isInfinite(const std::string& str);
bool	isChar(const std::string& str);

void	printChar(const std::string& str);
void	printInt(const std::string& str);
void	printFloat(const std::string& str);
void	printDouble(const std::string& str);

int		convertToInt(const std::string& str);
int		convertToChar(const std::string& str);
int		convertToFloat(const std::string& str);
int		convertToDouble(const std::string& str);
#endif

