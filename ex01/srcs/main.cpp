#include "RPN.hpp"

int main(int ac, char **av) 
{
	std::string input;
	if (ac < 2) {
		std::cerr << "Need one argument\n";
		return 1;
	} else if (ac > 2) {
		for (int i = 1; i < ac; i++) {
			input += std::string(av[i]) + " ";
		}
	} else {
		input = std::string(av[1]);
	}
	std::cout << "Input: "<< input << std::endl;
	RPN polish(input);

	try {
		std::cout << "result: " << polish.exec() << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;

}	
