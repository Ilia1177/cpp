#include "Data.hpp"

Data::Data(void) {};

Data::Data(const std::string& newstr, int v): str(newstr), value(v) {};

Data::Data(const Data& other) {
	this->value = other.value;
	this->str = other.str;
}

Data::~Data(void) {};

Data & Data::operator=(const Data& other) {
	if (this != &other) {
		this->value = other.value;
		this->str = other.str;
	}
	return (*this);
}
