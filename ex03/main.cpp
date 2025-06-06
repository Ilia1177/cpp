#include "Point.hpp"

int main( void ) {
	Point a(-4, .0f);
	Point const b( 0.0f, 8.0f );
	Point c(6, 0);
	Point pt(6,0); // out
	Point ptin(-1.36053f, 2.16182f);

	std::cout << "a=" << a << std::endl;
	std::cout << "b=" << b << std::endl;
	std::cout << "c=" << c << std::endl;
	std::cout << "pt=" << pt << std::endl;
	if (bsp(a, b, c, pt))
		std::cout << pt << " is IN" << std::endl;
	else
		std::cout << pt << " is OUT" << std::endl;

	if (bsp(a, b, c, ptin))
		std::cout << ptin << " is IN" << std::endl;
	else
		std::cout << ptin << "point is OUT" << std::endl;
	c = a;
	std::cout << "a=" << a << std::endl;
	std::cout << "c=" << c << std::endl;


	return (0);
}
