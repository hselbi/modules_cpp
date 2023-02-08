#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) 
{
    Point a(0.0, 0.0);
    Point b(0.0, 4.0);
    Point c(5.0, 0.0);
    Point p(1.0, 1.0);

    bsp(a, b, c, p);
    return 0;
}
