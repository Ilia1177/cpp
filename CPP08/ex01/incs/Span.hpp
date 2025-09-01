#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <stdexcept>
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
		size_t		index(void) const;
		void		assign(size_t, int);
		void		assign(const int*, const int*);
		const int	*begin(void) const;
		const int	*end(void) const;

	private:
		size_t	_size;
		size_t	_index;
		int*	_tab;
};

std::ostream &operator<<(std::ostream& os, const Span& s);

#endif

