#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
private:
    int _fixedPointer;
    static const int _fracBots = 8;
public:
    Fixed(void); // default constructor
    Fixed(const Fixed& fixPoint); // copy constructor
    Fixed& operator=(const Fixed& fixPoint); // copy assignement operator 
    ~Fixed(); // destructor

    int getRawBits( void ) const;
    void setRawBits( int const raw );
};


#endif