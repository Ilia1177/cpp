#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
    public:
        Animal(void);
        Animal(const std::string& type);
        Animal(const Animal& other);
        Animal &operator=(const Animal &other);
        ~Animal();

		const std::string&	getType() const; 
		void	makeSound() const;
	protected:
		std::string _type;	

};

#endif

