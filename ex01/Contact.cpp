#include "PhoneBook.hpp"


//	void	Contact::setName(const std::string& name) {
//		name_ = name;
//	}
//
//	void	Contact::setPhone(const std::string& phone) {
//		phone_ = phone;
//	}

int			Contact::getIndex(void) const {
	return (index_);
}
std::string Contact::getFirstName(void) const {
	return (first_name_);
}

std::string Contact::getLastName(void) const {
	return (last_name_);
}

std::string Contact::getNickname(void) const {
	return (nickname_);
}

std::string	Contact::getSecret(void) const {
	return (darkest_secret_);
}

std::string	Contact::getPhone(void) const {
	return (phone_number_);
}

std::string	Contact::shortenStr(const std::string& str) const {
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	Contact::printNames(void) const {

	std::cout << std::setw(10) <<  "index" << "|";
	std::cout << std::setw(10) <<  "first name" << "|";
	std::cout << std::setw(10) <<  "last name" << "|";
	std::cout << std::setw(10) <<  "nickname" << "|" << std::endl;
	std::cout << std::setw(10) << "-----------------------------------------" << std::endl;
	std::cout << std::setw(10) <<  Contact::getIndex() << "|";
	std::cout << std::setw(10) <<  Contact::shortenStr(Contact::getFirstName()) << "|";
	std::cout << std::setw(10) <<  Contact::shortenStr(Contact::getLastName()) << "|";
	std::cout << std::setw(10) <<  Contact::shortenStr(Contact::getNickname()) << "|" << std::endl;
}

void	Contact::printDetails() const {
	std::cout << std::setw(10) << "RESULT:------------------------------------- " << std::endl;
	std::cout << std::setw(10) <<  "first name     :" << Contact::getFirstName() << std::endl;
	std::cout << std::setw(10) <<  "last name      :" << Contact::getLastName() << std::endl;
	std::cout << std::setw(10) <<  "nickname       :" << Contact::getNickname() << std::endl;
	std::cout << std::setw(10) <<  "darkest secret :" << Contact::getSecret() << std::endl;
	std::cout << std::setw(10) <<  "phone number   : " << Contact::getPhone() << std::endl;
}
