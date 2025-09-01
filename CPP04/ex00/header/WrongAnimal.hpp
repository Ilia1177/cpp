#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal(const std::string& type);
        WrongAnimal &operator=(const WrongAnimal &other);
        ~WrongAnimal();

		const std::string&	getType( void ) const;
		void		makeSound( void ) const; 
	protected:
		std::string _type;
};

#endif

