#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    public:
        DiamondTrap(void);
        DiamondTrap(const std::string& name);
        ~DiamondTrap();
		DiamondTrap &operator=(const DiamondTrap &other);

		void	whoAmI(void);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);



	private:
		std::string	_name;
};

#endif

