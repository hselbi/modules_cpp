#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

#define Vec     Point

class Point
{
private:
    Fixed const x;
    Fixed const y;
public:
    Point(void);
    Point(const Point &tar);
    Point( const float _x, const float _y);
    Point& operator=(const Point &tar);
    ~Point();

    const Fixed& getX(void) const;
    const Fixed& getY(void) const;
};

Vec operator-(const Point &pa, const Point &pb);
Fixed operator*(const Vec& v1, const Vec& v2);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif