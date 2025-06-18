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
        ~Character();

		AMateria* getMateria(int) const;
		const std::string&	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
		void				printInventory( void ) const;
};


#endif

