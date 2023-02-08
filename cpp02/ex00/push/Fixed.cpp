#include "Fixed.hpp"

Fixed::Fixed(void): _fixedPointer(0)
{
    std::cout << "[ Default constructor called ]" << std::endl;
}

Fixed::Fixed(const Fixed& fixPoint)
{
    std::cout << "[ Copy constructor called ]" << std::endl;
    this->_fixedPointer = fixPoint._fixedPointer;
}

Fixed& Fixed::operator=(const Fixed& fixPoint)
{
    std::cout << "[ Copy assignment operator calle ]" << std::endl;
    if (this != &fixPoint)
        this->_fixedPointer = fixPoint._fixedPointer;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "[ Destructor is Called ]" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "[ getRawBits member function called ]" << std::endl;
    return (this->_fixedPointer);
}

void Fixed::setRawBits( int const raw)
{
    std::cout << "[ setRawBits member function called ]" << std::endl;
    this->_fixedPointer = raw;
}