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

    // constructor that takes a const integer
    Fixed(const int x);

    // constructor that takes a const float-pointer
    Fixed(const float n);
    // a memeber function converts the fixed-point value to a floating-point value.
    float toFloat( void ) const;

    // a memeber function converts the fixed-point value to an integer value.
    int toInt( void ) const;

    int getRawBits( void ) const;
    void setRawBits( int const raw );
};



Fixed::Fixed(void)
{
    std::cout << "default constructor is called" << std::endl;
    Value = 0;
}

//copy constructor
Fixed::Fixed(const Fixed& fixPoint)
{
    std::cout << "Copy constructor called" << std::endl;
    Value = fixPoint.Value;
}

// copy assiging constructor

Fixed& Fixed::operator=(const Fixed& fixPoint)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &fixPoint)
        Value = fixPoint.getRawBits();
    return *this;

}
// destructor
Fixed::~Fixed(void)
{
    std::cout << "default destructor is called" << std::endl;
    
}

Fixed:: Fixed(const int x)
{
 
    Value = (x << fracBits);
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

//constructor for floating point
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

int main( void ) 
{
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b ); // copy
    a = Fixed( 1234.4321f ); // assignement
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