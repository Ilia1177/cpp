#ifndef HARL_HPP
#define HARL_HPP
# include <iostream>
# include <string>

# define DEBUG_MSG 		"debug msg"
# define INFO_MSG 		"info msg"
# define WARNING_MSG 	"warning msg"
# define ERROR_MSG 		"error msg"

class Harl {
	public :
		Harl();
		void		complain( std::string level );
		long long	asciiHash(const std::string& str);
	private :
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
};

#endif
