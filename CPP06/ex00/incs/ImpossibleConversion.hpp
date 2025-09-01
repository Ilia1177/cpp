#ifndef IMPOSSIBLECONVERSION_HPP
# define IMPOSSIBLECONVERSION_HPP
# include <exception>
# include <iostream>

class ImpossibleConversion: public std::exception
{
	public:
		const char* what() const throw();
};

#endif

