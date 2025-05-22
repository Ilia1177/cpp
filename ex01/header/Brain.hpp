#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
    public:
        Brain(void);
        Brain(const Brain *other);
        Brain &operator=(const Brain *other);
        ~Brain();
	private:
		std::string ideas[100];
};

#endif

