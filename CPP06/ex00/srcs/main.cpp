#include "ScalarConverter.hpp"

int main(int ac, char **av) {

	if (ac != 2)
		std::cout << "please give one argument" << std::endl;
	ScalarConverter::convert(av[1]);
}
