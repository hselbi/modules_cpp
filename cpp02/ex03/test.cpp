

#include "Point.hpp"

Vec operator-(const Point& p1, const Point& p2) {
  return Vec(((p1.getX()) - (p2.getX())).toFloat(),
              (p1.getY() - p2.getY()).toFloat());
}

Fixed operator*(const Vec& v1, const Vec& v2) {
  return Fixed((v1.getX() * v2.getY()) - v1.getY() * v2.getX());
}

bool operator~(const Fixed& f) {
  return f > Fixed(0);
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {
  Vec ab = a - b;
  Vec bp = b - point;

  Vec bc = b - c;
  Vec cp = c - point;

  Vec ca = c - a;
  Vec ap = a - point;

  if ((~(ab * bp) && ~(bc * cp) && ~(ca * ap))
    || (!(~(ab * bp)) && !(~(bc * cp)) && !(~(ca * ap))))
    return true;
  return false;
}


#define Vec               Point

class Point {
 private:
  Fixed const _x;
  Fixed const _y;

 public:
  const Fixed& getX(void) const;
  const Fixed& getY(void) const;

  Point& operator=(const Point& p);
  Point(void);
  Point(const float x, const float y);
  Point(const Point& p);
  ~Point(void);
};

Vec operator-(const Point& p1, const Point& p2);
Fixed operator*(const Vec& v1, const Vec& v2);
bool operator~(const Fixed& f);
bool bsp(Point const a, Point const b, Point const c, Point const point);
std::ostream& operator<<(std::ostream& o, const Point& p);

// #endif  // CIRCLE_04_CPP_MODULE_02_EX03_POINT_HPP_


const Fixed& Point::getX(void) const {
  return _x;
}

const Fixed& Point::getY(void) const {
  return _y;
}

Point& Point::operator=(const Point& p) {
  if (this != &p) {
    const_cast<Fixed&>(_x) = p.getX();
    const_cast<Fixed&>(_y) = p.getY();
  }
  return *this;
}

Point::Point(void)
  : _x(0), _y(0) {}

Point::Point(const float x, const float y)
  : _x(x), _y(y) {}

Point::Point(const Point& p)
  : _x(p.getX()), _y(p.getY()) {}

Point::~Point(void) {}

std::ostream& operator<<(std::ostream& o, const Point& p) {
  return o << "( " << p.getX().toFloat() << ", " << p.getY().toFloat() << " )";
}

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

// Copyright @bigpel66

// #include "Point.hpp"

int main(void) {
  Point a(0.0, 0.0);
  Point b(0.0, 4.0);
  Point c(5.0, 0.0);
  Point hit1(1.0, 1.0);
  Point hit2(10.0, 10.0);

  std::cout << "Point a is " << a << std::endl;
  std::cout << "Point b is " << b << std::endl;
  std::cout << "Point c is " << c << std::endl;
  std::cout << "Hit Point1 is " << hit1 << std::endl;
  std::cout << "Hit Point2 is " << hit2 << std::endl;
  std::cout << std::endl;
  std::cout << "Hit Point1 is " << (bsp(a, b, c, hit1) ? "inside " : "outside ")
    << "of the triangle!" << std::endl;
  std::cout << "Hit Point1 is " << (bsp(a, b, c, hit2) ? "inside " : "outside ")
    << "of the triangle!" << std::endl;
  return 0;
}
