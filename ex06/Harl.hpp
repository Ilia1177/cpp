#ifndef HARL_HPP
#define HARL_HPP
# include <iostream>
# include <string>

# define DEBUG_MSG 		"debug msg"
# define INFO_MSG 		"info"
# define WARNING_MSG 	"warning"
# define ERROR_MSG 		"error"

# define DEBUG_HASH 	64921139 
# define INFO_HASH 		2251950 
# define WARNING_HASH	79151840124
# define ERROR_HASH		66247144

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
