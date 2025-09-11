#ifndef DATA_HPP
# define DATA_HPP
# include <iostream>

struct Data
{
	std::string str;
	int value;

	Data();
	Data(const std::string&, int);
	Data(const Data& other);
	~Data();
	Data& operator=(const Data&);
		
};

#endif

