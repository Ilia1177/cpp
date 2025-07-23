#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP
#include <exception>
# include <iostream>

class Exception: public std::exception
{
	public:
		const char* what() const
};

#endif

