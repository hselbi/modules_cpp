#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    // a (x, y)
    // b (x, y)
    // c (x, y)

    // point (x, y)

    // xp * ya
    std::cout << a.getX() << ", " << a.getY() << std::endl;
    std::cout << b.getX() << ", " << b.getY() << std::endl;
    std::cout << c.getX() << ", " << c.getY() << std::endl;
    std::cout << point.getX() << ", " << point.getY() << std::endl;
    // float z = point * a;
    // float sum1 = point.getX() * a.getY() + a.getX() * b.getY() + b.getX() * point.getY();
    // float sum2 = point.getY() * a.getX() + a.getY() * b.getX() + b.getY() * point.getX();

    // std::cout << "this is the rest : " << (sum1 + sum2) << std::endl;

    return 1;
}