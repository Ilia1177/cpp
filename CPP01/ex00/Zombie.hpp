#ifndef		ZOMBIE_HPP
#define		ZOMBIE_HPP
# include	<iostream>
# include	<string>
# define	ANNOUNCE	": BraiiiiiiinnnzzzZ..."

class Zombie {
	public :
		Zombie() 				: _name("") {};
		Zombie(std::string name): _name(name) {};
		void		announce() const;
		std::string	getName() const;
		~Zombie();
	private:
		std::string _name;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif
