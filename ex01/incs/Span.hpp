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
        ~Span();

		int		shortestSpan(void);
		int		longestSpan(void);
		void	addNumber(int);

	private:
		size_t	_size;
		size_t	_index;
		int*	_tab;
};

#endif

