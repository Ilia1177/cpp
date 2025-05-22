#ifndef DOG_HPP
# define DOG_HPP
# include <Animal.hpp> 

class Dog: public Animal {
    public:
        Dog(void);
        Dog(const Dog& other);
        Dog &operator=(const Dog &other);
        virtual ~Dog();

		void				makeSound( void ) const;
		bool				setIdea(const std::string&, int);
		const std::string&	getIdea(int) const;
	private:
		Brain *_brain;
};

#endif

