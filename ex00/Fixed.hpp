#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
    public:
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

        Fixed(void);
        Fixed(const Fixed& other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();
	private:
		int					_n;
		static const int	_d = 8;
};

#endif

