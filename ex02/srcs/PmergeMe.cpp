#include "PmergeMe.hpp"


elem_s::elem_s() {};
elem_s::elem_s(int val, std::string lab): key(val), label(lab), pairIndex(-1) {};
elem_s::elem_s(int val): key(val), label(""), pairIndex(-1) {};
elem_s::elem_s(const elem_s& other): key(other.key), label(other.label), pairIndex(other.pairIndex) {};
elem_s::~elem_s() {};
elem_s& elem_s::operator=(const elem_s &other)
{
	if (this != &other) {
		this->key = other.key; 
		this->label = other.label; 
		this->pairIndex = other.pairIndex;
	} 
	return *this;
}

bool elem_s::operator<(const elem_s &other) const {g_comparison++; return this->key < other.key;}
bool elem_s::operator==(const elem_s &other) const {g_comparison++; return this->key == other.key;}
bool elem_s::operator<(const int val) const {g_comparison++; return this->key < val;}
bool elem_s::operator>(const elem_s &other) const {g_comparison++; return this->key > other.key;}
bool elem_s::operator>(const int val) const {g_comparison++; return this->key > val;}

size_t g_comparison = 0;

int toInt(const std::string& str, char** endptr)
{
    *endptr = NULL;
	const char *cstr = str.c_str();

    errno = 0;
    long value = std::strtol(cstr, endptr, 10);

	if (errno == ERANGE || value > INT_MAX)
        throw std::invalid_argument("int overflow");
	else if (**endptr == '.')
		throw std::invalid_argument("decimal value are not valid number (only positive integer please)"); // float value
	else if (*endptr == cstr)
		throw std::invalid_argument("Invalid character");
	else if (value < 0)
		throw std::invalid_argument("negative numbers are forbiden");
    return static_cast<int>(value);
}

