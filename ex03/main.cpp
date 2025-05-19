#include "Point.hpp"

int main( void ) {
	Point a(-1, 1);
	Point const b( 0, 5 );
	Point c(5, 3);

	Point pt(1,1.5f);

	if (bsp(a, b, c, pt))
		std::cout << "point is IN" << std::endl;
	else
		std::cout << "point is OUT" << std::endl;
	return (0);
}
