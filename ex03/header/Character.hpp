#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
		AMateria	*_inventory[4];
		std::string	_name;

    public:
        Character(void);
        Character(const std::string& name);
        Character(const Character& other);
        Character &operator=(const Character &other);
        virtual ~Character();

		virtual const std::string&	getName() const;
		virtual void				equip(AMateria* m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);
};

#endif

