#include <string>
#include <iostream>
//#include <cctype>
#define	FEED_BACK "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

void megaphone(int ac, char **av)
{
	std::string	arg;

	for (int i = 1; i < ac; ++i) {
		arg = av[i];
		for (size_t j = 0; j < arg.length(); ++j) {
			arg[j] = std::toupper(arg[j]);
		}
		if (i == ac - 1)
		std::cout << arg << std::endl;
		else
			std::cout << arg << " ";
	}
}

int main(int ac, char **av) {
	if (ac  < 2) {
		std::cout << FEED_BACK << std::endl;
	} else if (ac >= 2) {
		megaphone(ac, av);
	}
	return (0);
}
