#include "Point.hpp"

int main( void ) {
	Point a(-1, 1);
	Point const b( 0, 5 );
	Point c(5, 3);

	Point pt(5,3);

	if (bsp(a, b, c, pt))
		std::cout << "point is IN" << std::endl;
	else
		std::cout << "point is OUT" << std::endl;

	std::cout << "aX=" << a.getX() << std::endl;
	std::cout << "aY=" << a.getY() << std::endl;
	return (0);
}
