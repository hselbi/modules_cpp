#include "Point.hpp"
#include "Fixed.hpp"
Point::Point(void): x(0), y(0)
{
    std::cout << "[ Default Constructor Called ] " << std::endl;
}

Point::~Point()
{
    std::cout << "[ Destructor Called ] " << std::endl;
}

Point::Point(const Point &tar): x(tar.getX()), y(tar.getY())
{
    std::cout << "[ Copy Constructor Called ] " << std::endl;
}

Point::Point( const float _x, const float _y): x(_x), y(_y)
{
    // std::cout << "this is coor => " << x << ", " << y << std::endl;
    std::cout << "[ Constructor parameterized Called ] " << std::endl;
}

Point& Point::operator=(const Point &tar)
{
    std::cout << "[ Copy Assignment Operator Overload Called ] " << std::endl;
    if (this != &tar)
    {
        const_cast<Fixed &>(x) = tar.getX();
        const_cast<Fixed &>(y) = tar.getY();
    }
    return *this;
}

const Fixed& Point::getX(void) const {
    return x;
}

const Fixed& Point::getY(void) const {
    return y;
}



Vec operator-(const Point& pa, const Point& pb)
{
    return Vec(((pa.getX()) - (pb.getX())).toFloat(), ((pa.getY()) - (pb.getY())).toFloat());
}

Fixed operator*(const Vec& pa, const Vec& pb)
{
    return (Vec(((pa.getX()) - (pb.getX()))))
}
