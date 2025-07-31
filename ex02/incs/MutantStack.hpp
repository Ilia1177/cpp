#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
    public:
		typedef typename std::stack<T, Container>::container_type container_type;
		typedef typename container_type::iterator iterator;
		typedef typename container_type::const_iterator const_iterator;


		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
};

# include "MutantStack.tpp"

#endif

