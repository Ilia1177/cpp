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

		//constructors
		Fixed(const int n);
		Fixed(const float f);
        Fixed(void);
        Fixed(const Fixed& other);

        Fixed &operator=(const Fixed &other);
		//logic operators
        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;
		//bits operations
        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;
		//increment && decrement
    	Fixed &operator++();
        Fixed operator++(int);
    	Fixed &operator--();
        Fixed operator--(int);

		//functions
		static const Fixed &max(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &min(Fixed &a, Fixed &b);
		//destructor
        ~Fixed(void);
	private:
		int					_rawValue;
		static const int	_fractionalBits = 8;
};

std::ostream &operator<<(std::ostream& os, const Fixed &other);
#endif

