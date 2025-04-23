#include "Harl.hpp"

Harl::Harl() {}

void	Harl::complain( std::string level ) {

	void		(Harl::*ptr[4])() = {	&Harl::debug, 
										&Harl::info,
										&Harl::warning,
										&Harl::error 	};
	std::string trigger[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; ++i) {
		if (level == trigger[i]) {
			(this->*ptr[i])();
			return ;
		}
	}
	std::cout << "IDK WHAT TO SAY" << std::endl;
}

void	Harl::debug( void ) {
	std::cout << DEBUG_MSG << std::endl;
}
void	Harl::info( void ) {
	std::cout << INFO_MSG << std::endl;
}
void	Harl::warning( void ) {
	std::cout << WARNING_MSG << std::endl;
}
void	Harl::error( void ) {
	std::cout << ERROR_MSG << std::endl;
}
