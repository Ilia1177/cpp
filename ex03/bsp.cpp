#include "Point.hpp"

static Fixed	det(Point const a, Point const b, Point const c) {
	Fixed det;

	det = (a.getX() - c.getX()) * (b.getY() - c.getY())
			- (b.getX() - c.getX()) * (a.getY() - c.getY());
	return det;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed d1, d2, d3;
	bool neg, pos;

	d1 = det(point, a, b);
	d2 = det(point, b, c);
	d3 = det(point, c, a);

	neg = (d1 <= 0) || (d2 <= 0) || (d3 <= 0);
	pos = (d1 >= 0) || (d2 >= 0) || (d3 >= 0);
	return !(neg && pos);
}	
