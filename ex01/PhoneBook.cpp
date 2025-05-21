#include "PhoneBook.hpp"

void	PhoneBook::saveInput(const std::string& str, std::string *input) {
	std::string value;
	std::cout << str; 
	while (value.empty()) {
		if (!std::getline(std::cin, value)) {
			exitPhoneBook();
		} else if (value.empty()) {
			std::cout << "This field cannot be empty. Please try again !" << std::endl;
			std::cout << str; 
		}
	}
	*input = value;
}

void	PhoneBook::addContact()
{
	std::string	first;
	std::string	last;
	std::string nickname;
	std::string secret;
	std::string phone;

	saveInput("Name it please: ", &first);
	saveInput("Give him a last name: ", &last);
	saveInput("little nickname: ", &nickname); 
	saveInput("A word about his terrible history: ", &secret);
	saveInput("A number where we can contact him: ", &phone);
	if (contact_nb_ >= 8) {
		contact_[7] = Contact(first, last, nickname, secret, phone, 7);
	} else {
		contact_[contact_nb_] = Contact(first, last, nickname, secret, phone, contact_nb_);
		contact_nb_++;
	}
	std::cout << "Contact added !" << std::endl;
}

void	PhoneBook::printTab(void) const {
	std::cout << std::setw(10) <<  "index" << "|";
	std::cout << std::setw(10) <<  "first name" << "|";
	std::cout << std::setw(10) <<  "last name" << "|";
	std::cout << std::setw(10) <<  "nickname" << "|" << std::endl;
	std::cout << std::setw(10) << "-----------------------------------------" << std::endl;
}

void	PhoneBook::exitPhoneBook() const {
	std::cout << "Exiting" << std::endl;
	exit(0);
}

void	PhoneBook::searchContact() const {
	int			found;
	int			i;
	int			index;
	std::string		input;

	if (contact_nb_ == 0) {
		std::cout << "No one's here ??" << std::endl;
		return ;
	}
	printTab();
	for (i = 0; i < contact_nb_; ++i) {
		contact_[i].printNames();
	}
	found = 0;
	std::cout << "Enter index of contact to display: ";
	if (!std::getline(std::cin, input))
		exitPhoneBook();
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
