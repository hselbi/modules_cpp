#include <iostream>
class Fixed
{
private:
    int FixedPointer;
    static const int fracBits = 8;
public:
    Fixed(void);
    // copy constructor
    // copy assigning constructor
    ~Fixed(void);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};


Fixed::Fixed(void)
{
    std::cout << "default constructor is called" << std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "default destructor is called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->FixedPointer);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->FixedPointer = raw;
}

int main( void )
{
    Fixed a;
    Fixed b(a);
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}