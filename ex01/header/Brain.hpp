#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
    public:
        Brain(void);
        Brain(const Brain &other);
        Brain &operator=(const Brain &other);
        ~Brain();

		const std::string&	getIdea(int) const;
		bool 				setIdea(const std::string& idea, int);
	private:
		std::string ideas[100];
};

#endif

