#ifndef CONTACT_HPP
# define CONTACT_HPP
# define DEFAULT "Available commands are ADD, SEARCH & EXIT."
# include <iostream>
# include <cstdlib>
# include <string>
# include <sstream>
# include <iomanip> 

class Contact {
	public :
		Contact()
			: first_name_(""), last_name_(""), nickname_(""),
			darkest_secret_(""), phone_number_(""), index_(0) {};
		Contact(std::string first, std::string last, std::string nickname, std::string secret, std::string phone, int index)
			:	first_name_(first), 
				last_name_(last), 
				nickname_(nickname), 
				darkest_secret_(secret),
				phone_number_(phone),
				index_(index)	{};
		int		getIndex() const;
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getSecret() const;
		std::string getPhone() const;
		std::string shortenStr(const std::string& str) const;
		void		printDetails() const;
		void		printNames() const;
	private :
		std::string	first_name_;
		std::string last_name_;
		std::string	nickname_;
		std::string darkest_secret_;
		std::string phone_number_;
		int			index_;
};

class PhoneBook {
	public :
		PhoneBook()	: contact_nb_(0) {};
		void	searchContact() const;
		void	addContact();
		void	exitPhoneBook() const;
		void	printTab(void) const;
		void	saveInput(const std::string& str, std::string *input) const;
	private :
		int		contact_nb_;
		Contact	contact_[8];
};
#endif
