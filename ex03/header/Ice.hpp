#ifndef ICE_HPP
# define ICE_HPP
# include <iostream>
# include <AMateria.hpp>

class Ice
{
    public:
        Ice(void);
        Ice(const Ice& other);
        Ice &operator=(const Ice &other);
        ~Ice();
};

#endif

