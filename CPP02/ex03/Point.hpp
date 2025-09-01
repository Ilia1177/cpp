#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
    public:
		Point(void);
		Point(const Point& other);
		Point(const float x, const float y);
		Point(const Fixed x, const Fixed y);
		Point operator=(const Point &other);
		~Point();

		Fixed getX( void ) const;
		Fixed getY( void ) const;

	private:
		Fixed const _x;
		Fixed const _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point );

std::ostream &operator<<(std::ostream& os, const Point &other);
#endif

