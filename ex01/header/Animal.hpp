#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <Brain.hpp>

class Animal
{
    public:
		Animal(void);
		Animal(const std::string& type);
		Animal(const Animal& other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();

		const std::string&	getType() const; 
		void	makeSound() const;
	protected:
		std::string	_type;	
};

#endif
