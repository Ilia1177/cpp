#include "PmergeMe.hpp"

// Default constructor
PmergeMe::PmergeMe(void)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
PmergeMe::~PmergeMe(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

