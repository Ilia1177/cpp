#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <ctime>
# include <cstdlib>
# include <stdexcept>
# include <numeric>
# include <algorithm>
# include <vector>
# define ABS(x) ((x) < 0 ? -(x) : (x))

class Span
{
    public:
        Span(size_t);
        Span(const Span& other);
        Span &operator=(const Span &other);
        int &operator[](const size_t index);
        const int &operator[](const size_t index) const;
        ~Span();

		size_t		shortestSpan(void);
		size_t		longestSpan(void);
		void		addNumber(int);
		size_t		size(void) const;
		size_t		max(void) const;
		void		assign(size_t, int);
		void		assign(std::vector<int>::iterator, std::vector<int>::iterator);
		void		rfill(int min, int max);

		std::vector<int>::iterator begin(void); 
		std::vector<int>::iterator end(void); 
	private:
		size_t	_index;
		size_t	_max;
		std::vector<int> _vec;
};

std::ostream &operator<<(std::ostream& os, const Span& s);

#endif

