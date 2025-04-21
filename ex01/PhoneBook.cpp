#include "PhoneBook.hpp"
//	static PhoneBook createCharacter() {
//
//	}

void	PhoneBook::addContact()
{
	std::string	first;
	std::string	last;
	std::string nickname;
	std::string secret;
	std::string phone;

	std::cout << "Name it please : "; 
	std::getline(std::cin, first);
	std::cout << "Give him a last name: ";
	std::getline(std::cin,  last);
	std::cout << "little nickname : "; 
	std::getline(std::cin, nickname);
	std::cout << "A word about his terrible history : ";
	std::getline(std::cin, secret);
	std::cout << "A number where we can contact him: ";
	std::getline(std::cin,  phone);


	if (contact_nb_ >= 8) {
		contact_[7] = Contact(first, last, nickname, secret, phone, 7);
	} else {
		contact_[contact_nb_] = Contact(first, last, nickname, secret, phone, contact_nb_);
		contact_nb_++;
	}
	std::cout << "Contact added !" << std::endl;
}

void	PhoneBook::exitPhoneBook() const
{
	std::cout << "Exiting" << std::endl;
	exit(0);
}

void	PhoneBook::searchContact() const
{
	int			found;
	int			i;
	int			index;
	std::string		input;

	if (contact_nb_ == 0) {
		std::cout << "No one's here ??" << std::endl;
		return ;
	}
	for (i = 0; i < contact_nb_; ++i) {
		contact_[i].printNames();
	}
	found = 0;
	std::cout << "Enter index of contact to display: ";
	std::getline(std::cin, input);

	std::stringstream ss(input);     // Create stringstream
	ss >> index;                    // Convert to int
	if (ss.fail()) {
		std::cout << "Invalid number!" << std::endl;
		return ;
	}
	for (i = 0; i < contact_nb_; ++i) {
			if (contact_[i].getIndex() == index) {
				contact_[i].printDetails();
				found = 1;
			}
		}
	if (!found)
		std::cout << "Contact not found." << std::endl;
}
