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

		virtual bool				setIdea(const std::string&, int) = 0;
		virtual const std::string&	getIdea(int) const = 0;
		virtual void				makeSound() const = 0;
		const std::string&			getType() const; 
	protected:
		std::string	_type;	
};

#endif
