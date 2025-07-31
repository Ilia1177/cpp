#include "Span.hpp"
#include <stdexcept>

// Destructor
Span::~Span(void) {delete [] _tab;}

// Default constructor
Span::Span(size_t n): _size(n), _index(0) {_tab = new int[n];}

// Copy constructor
Span::Span(const Span &other): 
	_size(other._size), _index(other._index), _tab(new int[other._size]) {
	for (size_t i = 0; i < other._size; ++i) {
		this->_tab[i] = other._tab[i];
	}
}

// Assignment operator overload
Span &Span::operator=(const Span &other) {
	if (this != &other) {
		if (this->_tab) delete [] _tab;
		this->_index = other._index;
		this->_size = other._size;
		this->_tab = new int[this->_size];
		for (size_t i = 0; i < this->_size; ++i) {
			this->_tab[i] = other._tab[i];
		}
	}
    return (*this);
}

const int& Span::operator[](const size_t index) const {
	if (index >= _size)
		throw std::out_of_range("out of range");
	return _tab[index];
}

int& Span::operator[](const size_t index) {
	if (index >= _size)
		throw std::out_of_range("out of range");
	return _tab[index];
}

size_t Span::size(void) const {return _size;}

size_t Span::index(void) const {return _index;}

void Span::addNumber(int num) {
	if (_index >= _size)
		throw std::out_of_range("Span is full");
	this->_tab[_index++] = num;
}

size_t Span::shortestSpan() {
	if (_size <= 1 || _index <= 1)
		throw std::out_of_range("No span can be found");

	size_t	currentSpan;
	size_t	shortest = ABS(_tab[0] - _tab[1]);

	for (size_t i = 0; i < _index; ++i) {
		for (size_t j = i + 1; j < _index; ++j) {
			currentSpan = ABS(_tab[i] - _tab[j]);
			if (currentSpan < shortest)
				shortest = currentSpan;
		}
	}
	return (shortest);
}

size_t Span::longestSpan(void) {
	if (_size <= 1 || _index <= 1)
		throw std::out_of_range("No span can be found");

	int	currentSpan;
	int longest = ABS(_tab[0] - _tab[1]);

	for (size_t i = 0; i < _index; ++i) {
		for (size_t j = i + 1; j < _index; ++j) {
			currentSpan = ABS(_tab[i] - _tab[j]);
			if (currentSpan > longest)
				longest = currentSpan;
		}
	}
	return (longest);
}

const int* Span::begin(void) const {
	return _tab;
}

const int* Span::end(void) const {
	return _tab + _index;
}

void Span::assign(size_t n, int value) {
	if (_tab) delete [] _tab;
	_size = n;
	_index = n;
	_tab = new int[n];
	for (size_t i = 0; i < n; ++i) {
		_tab[i] = value;
	}
}

//Be carreful to give pointer from the same object or it will have an UNDEFINED BEHAVIOR
void Span::assign(const int* begin, const int* end) {
	if (begin > end)
		throw std::invalid_argument("begin > end");
	if (_tab) delete [] _tab;
	_size = end - begin;
	_index = _size;
	_tab = new int[_size];
	size_t i = 0;
	for (const int *it = begin; it < end && i < _size; ++it) {
		_tab[i++] = *it;
	}
}

std::ostream &operator<<(std::ostream& os, const Span& s) {
	for (size_t i = 0; i < s.index(); ++i) {
		os << s[i];
		if (i != s.index() - 1) os << ", ";
	}
	return os;
}
