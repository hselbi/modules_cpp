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
    
    // operator overload: 6 comparison operators
    bool operator>(const Fixed& fixPoint);
    bool operator>=(const Fixed& fixPoint);
    bool operator<(const Fixed& fixPoint);
    bool operator<=(const Fixed& fixPoint);
    bool operator==(const Fixed& fixPoint);
    bool operator!=(const Fixed& fixPoint);

    // operator overload: 4 arthemetic operators
    Fixed operator+(const Fixed& fixPoint);
    Fixed operator-(const Fixed& fixPoint);
    Fixed operator*(const Fixed& fixPoint);
    Fixed operator/(const Fixed& fixPoint);

    // operator overload: 4 increment/decriment (pre/post for both)
    Fixed operator++(int);
    Fixed operator++();
    Fixed operator--(int);
    Fixed operator--();

    // 4 static member function (min/max)

    static Fixed min(Fixed& a, Fixed& b);
    static Fixed min(const Fixed& a, const Fixed& b);
    static Fixed max(Fixed& a, Fixed& b);
    static Fixed max(const Fixed& a, const Fixed& b);
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixPoint);

#endif