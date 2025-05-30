#ifndef		ZOMBIE_HPP
#define		ZOMBIE_HPP
# include	<iostream>
# include	<string>
# include	<sstream>
# define	ANNOUNCE	": BraiiiiiiinnnzzzZ..."

class Zombie {
	public :
		Zombie();
		Zombie(std::string name): _name(name) {};
		void		announce() const;
		std::string	getName() const;
		void		setName(std::string& name);
		~Zombie();
	private:
		std::string _name;
};

Zombie* zombieHorde(int N, std::string name); 
Zombie*	newZombie( std::string name );

#endif
