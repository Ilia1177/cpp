#include "RPN.hpp"

int main(int ac, char **av) 
{
	if (ac < 2) {
		std::cerr << "Need one argument\n";
		return 1;
	}
	RPN polish(av[1]);

	try {
		std::cout << "result: " << polish.exec() << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;

}	
