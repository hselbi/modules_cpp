#include <iostream>
#include <cmath>
class Fixed
{
private:
    int Value;
    static const int fracBits = 8;
public:
    Fixed(void);
    Fixed(const Fixed& fixPoint);
    Fixed& operator=(const Fixed& fixPoint);
    ~Fixed(void);

    Fixed(const int x);
    Fixed(const float n);
    float toFloat( void ) const;
    int toInt( void ) const;

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    // operator overloading: operators of comparison
    bool operator>(const Fixed& fixPoint);
    bool operator<(const Fixed& fixPoint);
    bool operator>=(const Fixed& fixPoint);
    bool operator<=(const Fixed& fixPoint);
    bool operator==(const Fixed& fixPoint);
    bool operator!=(const Fixed& fixPoint);
    
    // operator overloading: operators of arithmetic
    Fixed operator+(const Fixed& fixPoint);
    Fixed operator-(const Fixed& fixPoint);
    Fixed operator/(const Fixed& fixPoint);
    Fixed operator*(const Fixed& fixPoint);

    // operator overloading: increment/ decrement

    Fixed operator++();
    Fixed operator++(int);
    Fixed operator--();
    Fixed operator--(int);

    // overload: member function that compare the
    static Fixed min(Fixed& a, Fixed& b);
    static Fixed min(const Fixed& a, const Fixed& b);
    static Fixed max(Fixed& a, Fixed& b);
    static Fixed max(const Fixed& a, const Fixed& b);
};



Fixed::Fixed(void)
{
    Value = 0;
}

Fixed::Fixed(const Fixed& fixPoint)
{
    Value = fixPoint.Value;
}

Fixed& Fixed::operator=(const Fixed& fixPoint)
{
    if (this != &fixPoint)
        Value = fixPoint.getRawBits();
    return *this;
}

Fixed::~Fixed(void)
{    
}

Fixed:: Fixed(const int x)
{
    Value = x << fracBits;
}
int Fixed::toInt( void ) const
{
    return (this->Value >> fracBits);
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->Value);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->Value = raw;
}

Fixed::Fixed(const float n) {
    Value = roundf(n * (1 << fracBits));
}

float Fixed::toFloat( void ) const {
    
    return (float)Value / (1 << fracBits);
}

std::ostream &operator<<(std::ostream & o, Fixed const & rhs) {
    o << rhs.toFloat();
    return o;
}

/*
* comparison
*/

bool Fixed::operator>(const Fixed& fixPoint)
{
    if (this->Value > fixPoint.Value)
        return (true);
    else    
        return (false);
}

bool Fixed::operator<(const Fixed& fixPoint)
{
    if (this->Value < fixPoint.Value)
        return (true);
    else    
        return (false);
}

bool Fixed::operator>=(const Fixed& fixPoint)
{
    if (this->Value >= fixPoint.Value)
        return (true);
    else    
        return (false);
}

bool Fixed::operator<=(const Fixed& fixPoint)
{
    if (this->Value <= fixPoint.Value)
        return (true);
    else    
        return (false);
}

bool Fixed::operator==(const Fixed& fixPoint)
{
    if (this->Value == fixPoint.Value)
        return (true);
    else    
        return (false);
}

bool Fixed::operator!=(const Fixed& fixPoint)
{
    if (this->Value != fixPoint.Value)
        return (true);
    else    
        return (false);
}

/*
* arithmetic
*/

Fixed Fixed::operator+(const Fixed& fixPoint)
{
    // Fixed tmp(Value + fixPoint.Value);
    // return tmp;
    Fixed tmp;
    tmp.Value = this->Value + fixPoint.Value;
    return(tmp);
}

Fixed Fixed::operator-(const Fixed& fixPoint)
{
    // Fixed tmp(Value - fixPoint.Value);
    // return tmp;
    Fixed tmp;
    tmp.Value = this->Value - fixPoint.Value;
    return(tmp);
}

Fixed Fixed::operator*(const Fixed& fixPoint)
{
    // Fixed tmp(Value * fixPoint.Value);
    // return tmp;
    Fixed tmp;
    tmp.Value = this->Value * fixPoint.Value;
    return(tmp);
}

Fixed Fixed::operator/(const Fixed& fixPoint)
{
    // Fixed tmp(Value / fixPoint.Value);
    // return tmp;
    Fixed tmp;
    tmp.Value = this->Value / fixPoint.Value;
    return(tmp);
}

/*
* increment
*/

Fixed Fixed::operator++()
{
    std::cout << "this is void: " << Value << std::endl;
    Value++;
    std::cout << "this is void: " << Value << std::endl;
    return(*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    this->Value++;
    return(tmp);
}

/*
* decrement
*/

Fixed Fixed::operator--()
{
    Value--;
    return(*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    this->Value--;
    return(tmp);
}

static Fixed min(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    else if (a.getRawBits() == b.getRawBits())
        return (a);
    else
        return (b);
}

static Fixed min(Fixed& a, Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    else if (a.getRawBits() == b.getRawBits())
        return (a);
    else
        return (b);
}

static Fixed max(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    else if (a.getRawBits() == b.getRawBits())
        return (a);
    else
        return (b);
}

static Fixed max(Fixed& a, Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    else if (a.getRawBits() == b.getRawBits())
        return (a);
    else
        return (b);
}

int main( void ) 
{
    float t = 15.82;

    t++;
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b ); // copy
    a = Fixed( 1234.4321f ); // assignement
    std::cout << "a is " << a << std::endl;
    std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}