#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
    public:
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;

		Fixed(const int n);
		Fixed(const float f);
        Fixed(void);
        Fixed(const Fixed& other);
        Fixed &operator=(const Fixed &other);
        ~Fixed(void);
	private:
		int					_rawValue;
		static const int	_fractionalBits = 8;
};

std::ostream &operator<<(std::ostream& os, const Fixed &other);
#endif

