#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <iostream>
# include "IMateriaSource.hpp"
//# include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria	*_stock[4];
    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource& other);
        MateriaSource &operator=(const MateriaSource &other);

		virtual ~MateriaSource();
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
};

#endif

