#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
private:
    int _fixedPointer;
    static const int _fracBots = 8;
public:
    Fixed(void); // default constructor
    Fixed(const int fp); // constructor parameterized
    Fixed(const float fp); // constructor parameterized

    Fixed(const Fixed& fixPoint); // copy constructor
    Fixed& operator=(const Fixed& fixPoint); // copy assignement operator 
    ~Fixed(); // destructor

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixPoint);

#endif