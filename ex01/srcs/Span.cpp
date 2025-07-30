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

void Span::addNumber(int num) {
	if (_index >= _size)
		throw std::out_of_range("Span is full");
	this->_tab[_index++] = num;
}

int Span::shortestSpan() {
	if (_size <= 1 || _index <= 1)
		throw std::out_of_range("No span can be found");

	int	currentSpan;
	int shortest = ABS(_tab[0] - _tab[1]);

	for (size_t i = 0; i < _index; ++i) {
		for (size_t j = i + 1; j < _index; ++j) {
			currentSpan = ABS(_tab[i] - _tab[j]);
			if (currentSpan < shortest)
				shortest = currentSpan;
		}
	}
	return (shortest);
}


