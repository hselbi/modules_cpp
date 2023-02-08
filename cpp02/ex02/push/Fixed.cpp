#include "Fixed.hpp"

Fixed::Fixed(void): _fixedPointer(0)
{
    // std::cout << "[ Default constructor called ]" << std::endl;
}

Fixed::Fixed(const int fp)
{
    // std::cout << "[ Int constructor called ] "<< std::endl;
    this->_fixedPointer = (fp << _fracBots);
}

Fixed::Fixed(const float fp)
{
    // std::cout << "[ Float constructor called ] "<< std::endl;
    this->_fixedPointer = roundf(fp * (1 << _fracBots));
}

Fixed::Fixed(const Fixed& fixPoint)
{
    // std::cout << "[ Copy constructor called ]" << std::endl;
    this->_fixedPointer = fixPoint._fixedPointer;
}

Fixed& Fixed::operator=(const Fixed& fixPoint)
{
    // std::cout << "[ Copy assignment operator called ]" << std::endl;
    if (this != &fixPoint)
        this->_fixedPointer = fixPoint._fixedPointer;
    return (*this);
}

Fixed::~Fixed()
{
    // std::cout << "[ Destructor is Called ]" << std::endl;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "[ getRawBits member function called ]" << std::endl;
    return (this->_fixedPointer);
}

void Fixed::setRawBits( int const raw)
{
    // std::cout << "[ setRawBits member function called ]" << std::endl;
    this->_fixedPointer = raw;
}

int Fixed::toInt( void ) const
{
    return (this->_fixedPointer >> _fracBots);
}

float Fixed::toFloat( void ) const
{
    return (float)_fixedPointer / (1 << _fracBots);
}

// overload operation

std::ostream &operator<<(std::ostream &o, Fixed const &fixPoint)
{
    o << fixPoint.toFloat();
    return o;
}


/*
??   operator overload: 6 comparison operators
*/

bool Fixed::operator>(const Fixed& fixPoint)
{
    if (this->_fixedPointer > fixPoint._fixedPointer)
        return true;
    else
        return false;
}

bool Fixed::operator>=(const Fixed& fixPoint)
{
    if (this->_fixedPointer >= fixPoint._fixedPointer)
        return true;
    else
        return false;
}

bool Fixed::operator<(const Fixed& fixPoint)
{
    if (this->_fixedPointer < fixPoint._fixedPointer)
        return true;
    else
        return false;
}

bool Fixed::operator<=(const Fixed& fixPoint)
{
    if (this->_fixedPointer <= fixPoint._fixedPointer)
        return true;
    else
        return false;
}

bool Fixed::operator==(const Fixed& fixPoint)
{
    if (this->_fixedPointer == fixPoint._fixedPointer)
        return true;
    else
        return false;
}

bool Fixed::operator!=(const Fixed& fixPoint)
{
    if (this->_fixedPointer == fixPoint._fixedPointer)
        return true;
    else
        return false;
}

/*
!   operator overload: 4 arthemetic operators
*/

Fixed Fixed::operator+(const Fixed& fixPoint)
{
    Fixed tmp;
    tmp._fixedPointer = this->_fixedPointer + fixPoint._fixedPointer;
    return tmp;
}

Fixed Fixed::operator-(const Fixed& fixPoint)
{
    Fixed tmp;
    tmp._fixedPointer = this->_fixedPointer - fixPoint._fixedPointer;
    return tmp;
}

Fixed Fixed::operator*(const Fixed& fixPoint)
{
    Fixed tmp;
    tmp._fixedPointer = (this->_fixedPointer * fixPoint._fixedPointer) >> _fracBots;
    return tmp;
}

Fixed Fixed::operator/(const Fixed& fixPoint)
{
    Fixed tmp;
    tmp._fixedPointer = ((float)this->_fixedPointer / fixPoint._fixedPointer) * (1 << _fracBots);
    return tmp;
}

/*
^   operator overload: 4 increment/decriment (pre/post for both)
*/
Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    this->_fixedPointer++;
    return (tmp);
}

Fixed Fixed::operator++()
{
    _fixedPointer++;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    this->_fixedPointer--;
    return (tmp);
}

Fixed Fixed::operator--()
{
    _fixedPointer--;
    return *this;
}

/*
&   4 static member function (min/max)
*/

Fixed Fixed::min(Fixed& a, Fixed& b)
{
    if (a.getRawBits() < a.getRawBits())
        return a;
    else if (a.getRawBits() == a.getRawBits())
        return a;
    else
        return b;
}

Fixed Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() < a.getRawBits())
        return a;
    else if (a.getRawBits() == a.getRawBits())
        return a;
    else
        return b;
}

Fixed Fixed::max(Fixed& a, Fixed& b)
{
    if (a.getRawBits() > a.getRawBits())
        return a;
    else if (a.getRawBits() == a.getRawBits())
        return a;
    else
        return b;
}

Fixed Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    else if (a.getRawBits() == b.getRawBits())
        return a;
    else
        return b;
}