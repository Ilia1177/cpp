#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap {
    public:
        DiamondTrap(void);
        DiamondTrap(const std::string& name);
        ~DiamondTrap();
};

#endif

