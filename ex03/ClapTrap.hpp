#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
    public:
        ClapTrap(void);
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& other);
        ClapTrap &operator=(const ClapTrap &other);
        ~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		
		unsigned int		getHitPoints() const;
		unsigned int		getEnergyPoints() const;
		unsigned int		getAttackDamage() const;
		const std::string&	getName() const;

		void	setHitPoints(unsigned int amount);
		void	setEnergyPoints(unsigned int amout);
		void	setAttackDamage(unsigned int amount);
		void	setName(const std::string& name); 
	private:
		std::string _name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

#endif

