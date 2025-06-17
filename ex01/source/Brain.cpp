#include "Brain.hpp"

// Default constructor
Brain::Brain(void) {
    std::cout << "Brain: Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Brain::Brain(const Brain& other) {
    std::cout << "Brain: Copy constructor called" << std::endl;
	for (size_t i = 0; i < 100; i++) {
		this->ideas[i] = other.ideas[i];
	}
    return ;
}

// Assignment operator overload
Brain &Brain::operator=(const Brain& other) {
	if (this != &other) {
		std::cout << "Brain: Assignment operator called" << std::endl;
		for (size_t i = 0; i < 100; i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
    return (*this);
}

// Destructor
Brain::~Brain(void) {
    std::cout << "Brain: Destructor called" << std::endl;
    return ;
}

const std::string& Brain::getIdea(int nb) const {
	if (nb < 0 || nb >= 100) {
    	static const std::string empty = "Error: idea goes from 0 to 99";
        return empty;
    }
	return ideas[nb];
}

bool Brain::setIdea(const std::string& idea, int nb) {
	if (nb >= 0 && nb < 100) {
		this->ideas[nb] = idea;
		return true;
	}
	std::cout << "Error: idea goes from 0 to 99" << std::endl;
	return false;
}

