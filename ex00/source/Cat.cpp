#include <Cat.hpp>

// Default constructor
Cat::Cat(void)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Cat::Cat(const Cat &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
Cat::~Cat(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

void	Cat::makeSound(void) const {
	std::cout << "Miaou" << std::endl;
}
