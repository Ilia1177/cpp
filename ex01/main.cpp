#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	cmd;

	while (1) {
		std::cout << "type a command :";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			phoneBook.addContact();
		else if (cmd == "SEARCH")
			phoneBook.searchContact();
		else if (cmd == "EXIT")
			phoneBook.exitPhoneBook();
		//else if (cmd == "\n")
		//	continue ;
		else
			std::cout << DEFAULT << std::endl;
	}
}
