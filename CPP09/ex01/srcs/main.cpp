#include "RPN.hpp"

int main(int ac, char **av) 
{
	if (ac < 2)
		return 1;
	RPN polish;

	try {
		polish.exec(av[1]);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}	
