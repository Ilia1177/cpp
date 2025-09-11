#pragma once 
#include "Array.hpp"

// Default constructor
template<typename T>
Array<T>::Array(void): _size(0), _tab(new T[0]()) {}

template<typename T>
Array<T>::Array(const size_t n): _size(n), _tab(new T[n]) {
	for (size_t i = 0; i < n; ++i) {
		_tab[i] = T();
	}
}

// Copy constructor
template<typename T>
Array<T>::Array(const Array &other): _size(other._size), _tab(new T[other._size]) {
	for (size_t i = 0; i < other._size; i++) {
		this->_tab[i] = other._tab[i];
	}
}

// Assignment operator overload
template<typename T>
Array<T> &Array<T>::operator=(const Array &other) {
	if (this != &other) {
		delete[] this->_tab;
		this->_size = other._size;
		this->_tab = new T[_size];
		for (size_t i = 0; i < _size; i++) {
			this->_tab[i] = other._tab[i];
		}
	}
    return (*this);
}

// Destructor
template <typename T>
Array<T>::~Array(void) { delete [] _tab; }

template<typename T>
T& Array<T>::operator[](size_t index) {
	if (index >= _size)
		throw std::out_of_range("Index is out of range");
    return _tab[index];
}

template<typename T>
const T& Array<T>::operator[](size_t index) const {
	if (index >= _size)
		throw std::out_of_range("Index is out of range");
    return _tab[index];
}

template<typename T>
size_t Array<T>::size() const {
    return _size;
}

template<typename A, typename B>
std::ostream& operator<<(std::ostream& os, const std::pair<A, B>& p) {
	return os << "(" << p.first << ", " << p.second << ")";
}

template<typename U>
std::ostream& operator<<(std::ostream& os, const Array<U>& array) {
    os << "[";
    for (size_t i = 0; i < array.size(); ++i) {
        os << array[i];
        if (i < array.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}


