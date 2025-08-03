#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange trader;

	(void)av;
	(void)ac;

	try {
		trader.getData("data.csv");
		trader.outputPrice(av[1]);
		//trader.printAll();
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
