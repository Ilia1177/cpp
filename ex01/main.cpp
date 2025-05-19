#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	cmd;

	while (true) {
		std::cout << "type a command :";
		if (!std::getline(std::cin, cmd))
			phoneBook.exitPhoneBook();
		else if (cmd == "ADD")
			phoneBook.addContact();
		else if (cmd == "SEARCH")
			phoneBook.searchContact();
		else if (cmd == "EXIT")
			phoneBook.exitPhoneBook();
		else 
			std::cout << DEFAULT << std::endl;
	}
}
