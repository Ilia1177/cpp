#include "PmergeMe.hpp"
//
//	// Default constructor
//	PmergeMe::PmergeMe(void)
//	{
//		std::cout << "Default constructor called" << std::endl;
//		return ;
//	}
//
//	// Copy constructor
//	PmergeMe::PmergeMe(const PmergeMe &other)
//	{
//		std::cout << "Copy constructor called" << std::endl;
//		(void) other;
//		return ;
//	}
//
//	// Assignment operator overload
//	PmergeMe &PmergeMe::operator=(const PmergeMe &other)
//	{
//		std::cout << "Assignment operator called" << std::endl;
//		(void) other;
//		return (*this);
//	}
//
//	// Destructor
//	PmergeMe::~PmergeMe(void)
//	{
//		std::cout << "Destructor called" << std::endl;
//		return ;
//	}
//
//
int toInt(const std::string& str, char** endptr)
{
    *endptr = NULL;
	const char *cstr = str.c_str();

    errno = 0;
    long value = std::strtol(cstr, endptr, 10);

	if (errno == ERANGE || value > INT_MAX)
        throw std::invalid_argument("int overflow");
	else if (**endptr == '.')
		throw std::exception(); // float value
	if (*endptr == cstr)
		throw std::invalid_argument("no conversion made");
    return static_cast<int>(value);
}

