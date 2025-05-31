#ifndef CAT_HPP
# define CAT_HPP
# include <Animal.hpp>

class Cat: public Animal {
    public:
        Cat(void);
        Cat(const Cat& other);
        Cat &operator=(const Cat &other);
        ~Cat();

		void				makeSound( void ) const;
		bool				setIdea(const std::string&, int);
		const std::string&	getIdea(int) const;
	private:
		Brain *_brain;
};

#endif

