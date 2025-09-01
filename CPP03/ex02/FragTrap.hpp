#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap(void);
        FragTrap(const std::string& name);
        virtual ~FragTrap();
		FragTrap &operator=(const FragTrap &other);

		void	highFivesGuys(void);
};

#endif

