#include "PhoneBook.hpp"

bool PhoneBook::isPrintable(const std::string& str) const {
	bool	allSpace;
	
	allSpace = true;
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!isprint(static_cast<unsigned char>(*it))) {
            return false;
        }
		if (!std::isspace(static_cast<unsigned char>(*it)))
			allSpace = false;
    }
	if (!allSpace)
		return true;
	return (false);
}

void	PhoneBook::saveInput(const std::string& str, std::string *input) const {
	std::string value;
	std::cout << str; 
	while (value.empty()) {
		if (!std::getline(std::cin, value)) {
			exitPhoneBook();
		} else if (value.empty() || !isPrintable(value)) {
			std::cout << "This field cannot be empty. Please try again !" << std::endl;
			std::cout << str;
			value.clear();
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
	static int	index;

	saveInput("Name it please: ", &first);
	saveInput("Give him a last name: ", &last);
	saveInput("little nickname: ", &nickname); 
	saveInput("A word about his terrible history: ", &secret);
	saveInput("A number where we can contact him: ", &phone);
	if (index > 7)
		index = 0;
	contact_[index] = Contact(first, last, nickname, secret, phone, index);
	if (contact_nb_ < 8)
		contact_nb_++;
	index++;
	std::cout << "Contact added !" << std::endl;
}

void	PhoneBook::printTab(void) const {
	std::cout << std::setw(10) <<  "index" << "|";
	std::cout << std::setw(10) <<  "first name" << "|";
	std::cout << std::setw(10) <<  "last name" << "|";
	std::cout << std::setw(10) <<  "nickname" << "|" << std::endl;
	std::cout << std::setw(10) << "---------------------------------------------";
	std::cout << std::endl;
}

void	PhoneBook::exitPhoneBook() const {
	std::cout << "Exiting" << std::endl;
	std::exit(0);
}

void	PhoneBook::searchContact() const {
	int				found;
	int				i;
	int				index;
	std::string		input;

	if (contact_nb_ == 0) {
		std::cout << "No one's here ??" << std::endl;
		return ;
	}
	printTab();
	for (i = 0; i < contact_nb_; ++i) {
		contact_[i].printNames();
	}
	saveInput("Enter index of contact to display: ", &input);
	std::stringstream ss(input);
	ss >> index;
	if (ss.fail()) {
		std::cout << "Invalid number!" << std::endl;
		return ;
	}
	found = 0;
	for (i = 0; i < contact_nb_; ++i) {
		if (contact_[i].getIndex() == index) {
			contact_[i].printDetails();
			found = 1;
		}
	}
	if (!found)
		std::cout << "Contact not found." << std::endl;
}
