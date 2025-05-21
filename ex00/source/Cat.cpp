#include <Cat.hpp>

// Default constructor
Cat::Cat(void)
{
    std::cout << "Cat: Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Cat::Cat(const Cat &other)
{
    std::cout << "Cat: Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat: Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
Cat::~Cat(void)
{
    std::cout << "Cat: Destructor called" << std::endl;
    return ;
}

void	Cat::makeSound(void) const {
	std::cout << "Miaou" << std::endl;
}
