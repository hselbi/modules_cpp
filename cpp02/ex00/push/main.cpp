#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;
    Fixed b( a ); // co
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    // std::cout << "hellos me" << std::endl;
    return 0;
}