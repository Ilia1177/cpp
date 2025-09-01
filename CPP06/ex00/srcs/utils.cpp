#include "ScalarConverter.hpp"

double getNaNd()
{
	union {
    	unsigned long long i;
    	double d;
	} u;
    u.i = 0x7FF8000000000000ULL;  // Quiet NaN pattern for double (IEEE 754)
    return u.d;
}

float getNaNf()
{
    union {
        unsigned int i;
        float f;
    } u;
    u.i = 0x7FC00000;
    return u.f;
}

bool	notANumber(const std::string& str)
{
	if (!isInt(str) && !isDouble(str) && !isFloat(str))
		return true;
	return false;
}

void	ft_c_str(const std::string& str, char *buff, size_t len)
{
	if (len == 0)
		return ;
	size_t i = 0;
	for (; i < len - 1 && str[i]; i++) {
		buff[i] = str[i];
	}
	buff[i] = '\0';
}

size_t ft_strlen(const std::string& str)
{
	size_t len;
	for (len = 0; str[len] != 0; len++);
	return len;
}
