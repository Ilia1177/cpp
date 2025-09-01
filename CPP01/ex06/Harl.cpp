#include "Harl.hpp"

Harl::Harl() {}

long long	Harl::asciiHash(const std::string& str) {

    long long result;

	result = 0;
    for (std::string::size_type i = 0; i < str.length(); ++i) {
        result = result * 31 + static_cast<int>(str[i]); 
	}
    return result;
}

void	Harl::complain( std::string level ) {

	void	(Harl::*ptr[4])() 		= {	&Harl::debug, 
										&Harl::info,
										&Harl::warning,
										&Harl::error	};

	switch (Harl::asciiHash(level))	{ 
		case (DEBUG_HASH):
				(this->*ptr[0])();
		case (INFO_HASH):
				(this->*ptr[1])();
		case (WARNING_HASH):
				(this->*ptr[2])();
		case (ERROR_HASH):
				(this->*ptr[3])();
				break ;
		default :
			std::cout << "Dunno what to say..." << std::endl;
			return ;
	}
}

void	Harl::debug( void ) {
	std::cout << "[ DEBUG ]: " << DEBUG_MSG << std::endl;
}

void	Harl::info( void ) {
	std::cout << "[ INFO ]: " << INFO_MSG << std::endl;
}
void	Harl::warning( void ) {
	std::cout << "[ WARNING ]: " << WARNING_MSG << std::endl;
}
void	Harl::error( void ) {
	std::cout << "[ ERROR ]: " << ERROR_MSG << std::endl;
}
