#ifndef HUMAN_B
# define HUMAN_B
# include "Weapon.hpp"

class HumanB {
	public:
		HumanB(std::string name);
		void		attack() const;
		void		setWeapon(Weapon* weapon);
		Weapon& 	getWeapon() const;
	private:	
		std::string	_name;
		Weapon*		_weapon;
};

#endif
