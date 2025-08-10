#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange trader;

	(void)av;
	(void)ac;

	try {
		trader.readData("data.csv");
	//	trader.printAll();
		trader.outputPrice(av[1]);
	} catch (std::exception& e) {
		std::cout << "Fatal error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
