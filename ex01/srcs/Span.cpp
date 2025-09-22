#include "Span.hpp"

// Destructor
Span::~Span(void) {}

// Default constructor
Span::Span(size_t n): _index(0), _max(n), _vec(n) {}

// Copy constructor
Span::Span(const Span &other): _index(other._index), _max(other._max), _vec(other._vec) {}

// Assignment operator overload
Span &Span::operator=(const Span &other) {
	if (this != &other) {
		this->_index = other._index;
		this->_max = other._max;
		this->_vec = other._vec;
	}
    return (*this);
}

const int& Span::operator[](const size_t index) const {
	if (index >= _index)
		throw std::invalid_argument("index not initialized");
	else if (index >= _max)
		throw std::out_of_range("index out of range");
	return _vec[index];
}

int& Span::operator[](const size_t index) {
	if (index >= _index)
		throw std::invalid_argument("index not initialized");
	else if (index >= _max)
		throw std::out_of_range("index out of range");
	return _vec[index];
}

size_t Span::size(void) const {return _index;}

size_t Span::max(void) const {return _max;}

void Span::addNumber(int num) {
	if (_index >= _max)
		throw std::out_of_range("Span is at max");
	_vec[_index++] = num;
}

size_t Span::shortestSpan() {
    if (_vec.size() < 2) {
        throw std::out_of_range("No span can be found");
    }
	std::vector<int>::iterator min_it;
    std::vector<int> tmp = _vec;
	
    std::sort(tmp.begin(), tmp.end());
    std::vector<int> diffs(tmp.size());
    std::adjacent_difference(tmp.begin(), tmp.end(), diffs.begin());
	min_it = std::min_element(diffs.begin() + 1, diffs.end()); 

    return static_cast<size_t>(*min_it);
}

size_t Span::longestSpan(void) {
	if (_vec.size() < 2) {
        throw std::out_of_range("No span can be found");
	}
	std::vector<int> tmp = _vec;

	std::sort(tmp.begin(), tmp.end());
	size_t diff = *(tmp.end() - 1) - *tmp.begin();

	return diff;
}

std::vector<int>::iterator Span::begin(void) {
	return _vec.begin();
}

std::vector<int>::iterator Span::end(void) {
	if (_index == 0) return _vec.end();
	return _vec.begin() + _index;
}

void Span::assign(size_t n, int value)
{
	if (n > _max) {
		_vec.assign(_max, value);
		_index = _max;
		throw std::out_of_range("reach maximum");
	}
	_vec.assign(n, value);
	_index = n;
}

//Be carreful to give pointer from the same object or it will have an UNDEFINED BEHAVIOR
void Span::assign(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (begin > end)
		throw std::invalid_argument("start is beyond end");
	if (static_cast<size_t>(end - begin) > _max) {
		_vec.assign(begin, begin + _max);
		_index = _max;
		throw std::out_of_range("out of range");
	}
	_vec.assign(begin, end);
	_index = static_cast<size_t>(end - begin);
}

void	Span::rfill(int min, int max) {
	for (size_t i = 0; i < _max; ++i) {
		_vec[i] = min + std::rand() % (max - min + 1);
	}
	_index = _max;
}

std::ostream &operator<<(std::ostream& os, const Span& s) {
	std::cout << "size: " << s.size() << " max: " << s.max() << "\n";
	for (size_t i = 0; i < s.size(); ++i) {
		os << s[i];
		if (i != s.size() - 1) os << ", ";
	}
	return os;
}
