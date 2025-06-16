#include "Fixed.hpp"

int main( void ) {
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	{
		std::cout << std::endl << "2 part:" << std::endl;
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		Fixed c = 50;

		c = a;

		if (b < c)
			std::cout << "b=" << b << " is < than c=" << c << std::endl;
		if (b > c)
			std::cout << "b=" << b << " is > than c=" << c << std::endl;
		if (b >= c)
			std::cout << "b=" << b << " is >= than c=" << c << std::endl;

		if (b <= c)
			std::cout << "b=" << b << " is <= than c=" << c << std::endl;
		if (b == c)
			std::cout << "b is equal to c" << std::endl;
		if (b != c)
			std::cout << "b is not equal to c" << std::endl;

		Fixed zero( 0.0005f );
		std::cout << b / (a + 0.02f) << std::endl;
		std::cout << b / a << std::endl;
		std::cout << "zero=" << zero << std::endl;
		std::cout << b / 0.005f << std::endl;
		std::cout << b / 0 << std::endl;
		std::cout << b / 2 << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
	}
	return (0);
}
