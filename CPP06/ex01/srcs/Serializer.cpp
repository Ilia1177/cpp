#include "Serializer.hpp"

// Default constructor
Serializer::Serializer(void)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Serializer::Serializer(const Serializer &other)
{
    std::cout<< "Copy constructor called" << std::endl;
    *this = other;
    return ;
}

// Assignment operator overload
Serializer &Serializer::operator=(const Serializer &other)
{
    std::cout << "Assignment operator called" << std::endl;
	(void)other;
    return (*this);
}

// Destructor
Serializer::~Serializer(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}


uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t value;

	value = reinterpret_cast<uintptr_t>(ptr);
	return value;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* value;

	value = reinterpret_cast<Data*>(raw);
	return value;
}
