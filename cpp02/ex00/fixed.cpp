#include <iostream>
class Fixed
{
private:
    int FixedPointer;
    static const int fracBits = 8;
public:
    // default constructor
    Fixed(void);
    // copy constructor
    Fixed(const Fixed& fixPoint);
    // copy assigning constructor
    Fixed& operator=(const Fixed& fixPoint);
    ~Fixed(void);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

// constructor 
Fixed::Fixed(void):FixedPointer(0)
{
    std::cout << "default constructor is called" << std::endl;
}

//copy constructor
Fixed::Fixed(const Fixed& fixPoint)
{
    std::cout << "Copy constructor called" << std::endl;
    FixedPointer = fixPoint.FixedPointer;
}

// copy assiging constructor

Fixed& Fixed::operator=(const Fixed& fixPoint)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &fixPoint)
        FixedPointer = fixPoint.getRawBits();
    return *this;

}
// destructor
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


// this is the main that in subject

int main( void )
{
    Fixed a;

    Fixed b(a); //copy constructor called
    
    Fixed c;
    c = b; // copy constructor called
    
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}