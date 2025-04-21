#ifndef WEAPON_HPP
#define WEAPON_HPP
# include <iostream>
# include <string>

class Weapon {
	public:
		Weapon(const std::string& type);
		const std::string&  getType() const;
		void				setType(const std::string& type);
	private:
		std::string	_type;
};

class HumanA {
	public:
		HumanA(std::string name, Weapon& weapon);
		void		attack() const;
		void		setWeapon(Weapon& weapon);
	private:
		std::string	_name;
		Weapon&		_weapon;
};

class HumanB {
	public:
		HumanB(std::string name);
		void		attack() const;
		void		setWeapon(Weapon& weapon);
		Weapon& 	getWeapon() const;
	private:	
		std::string	_name;
		Weapon*		_weapon;
};

#endif
