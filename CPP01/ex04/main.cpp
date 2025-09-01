#include "FileHandler.hpp"

int	main(int ac, char **av) {

	FileHandler	file;
	int			status;

	if (ac != 4) {
		std::cout << USAGE_MSG << std::endl;
		return (1);
	} 
	status = file.openInfile(av[1]);
	if (!status)
		status = file.edit(av[2], av[3]);
	return (status);
}
