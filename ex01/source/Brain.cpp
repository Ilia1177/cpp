#include "Brain.hpp"

// Default constructor
Brain::Brain(void) {
    std::cout << "Brain: Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Brain::Brain(const Brain *other) {
    std::cout << "Brain: Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
Brain &Brain::operator=(const Brain *other) {
    std::cout << "Brain Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
Brain::~Brain(void) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

