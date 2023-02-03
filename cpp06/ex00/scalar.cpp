#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <math.h>
#include <cstring>
#include <iomanip>

class Scalar
{
private:
    bool _err;
    std::string _in;
    double _val;
public:
    Scalar(void); // default
    Scalar(std::string inp); // parameterized
    Scalar(const Scalar& targ); // copy
    Scalar &operator=(const Scalar& targ); // overload
    ~Scalar();

    // getters 
    bool getErr() const;
    std::string getIn() const;
    double getVal() const;

    // memeber functions

    char toChar(void) const;
    int toInt(void) const;
    float toFloat(void) const;
    double toDouble(void) const;
};

char Scalar::toChar(void) const
{
    return (static_cast<char>(_val));
}

int Scalar::toInt(void) const
{
    return (static_cast<int>(_val));
}

float Scalar::toFloat(void) const
{
    return static_cast<float>(_val);
}

double Scalar::toDouble(void) const
{
    return (static_cast<double>(_val));
}



bool    Scalar::getErr() const
{
    return (_err);
}

std::string Scalar::getIn() const
{
    return (_in);
}

double Scalar::getVal() const
{
    return (_val);
}

Scalar::Scalar(void): _err(false), _in(""), _val(0.0)
{
    std::cout << "[ Default Constructor Called ]" << std::endl;
}

double stringToDouble(const std::string& _in)
{
    double _val;
    char *ptr = NULL;
    _val = std::strtod(_in.c_str(), &ptr);

    return (_val);
}

Scalar::Scalar(std::string inp): _err(false), _in(inp), _val(0.0)
{
    std::cout << "[ Parameterized Constructor Called ]" << std::endl;

    std::cout << "this is a in " <<_in << std::endl;
    std::cout << "this is a val " << _val << std::endl;
    std::cout << "==> " << stringToDouble(_in) << std::endl;

    
}

Scalar::Scalar(const Scalar& targ): _err(false), _in(targ._in), _val(targ._val)
{
    std::cout << "[ Copy Constructor Called ]" << std::endl;
}

Scalar &Scalar::operator=(const Scalar& targ)
{
    std::cout << "[ Operator Overloading Called ]" << std::endl;
    if (this != &targ)
    {
        this->_err = targ._err;
        this->_in = targ._in;
        this->_val = targ._val;
    }
    return (*this);
}


Scalar::~Scalar()
{
    std::cout << "[ Destructor Called ]" << std::endl;
}

void charPrintable(const Scalar& scal)
{
    if (scal.getErr())
    {
        std::cerr << "Converting Failed" << std::endl;
        return ;
    }
    std::cout << "char: ";
    if (isnan(scal.getVal()) || std::isinf(scal.getVal()))
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(scal.toChar()))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << scal.toChar() << "'" << std::endl;
}

void intPrintable(const Scalar& scal)
{
    if (scal.getErr())
    {
        std::cerr << "Converting Failed" << std::endl;
        return ;
    }
    std::cout << "int: ";
    if (isnan(scal.getVal()) || std::isinf(scal.getVal()))
        std::cout << "impossible" << std::endl;
    else
        std::cout << scal.toInt() << std::endl;
}

void floatPrintable(const Scalar& scal)
{
    if (scal.getErr())
    {
        std::cerr << "Converting Failed" << std::endl;
        return ;
    }
    std::cout << "this is for nan " << scal.getVal() << std::endl;
    std::cout << "this is for inf " << std::isinf(scal.getVal()) << std::endl;
    std::cout << "get floating " << scal.toFloat() << std::endl;
    std::cout << "get floating 64" << static_cast<int32_t>(scal.toFloat()) << std::endl;
    if (isnan(scal.getVal()) || std::isinf(scal.getVal()))
    {
        std::cout << "float: " << scal.toFloat() << "f" << std::endl;
    }
    if (scal.toFloat() == static_cast<int64_t>(scal.toFloat()))
        std::cout << "float: " << scal.toFloat() << std::endl;
    else
        std::cout << "float: " << std::setprecision(3)
      << scal.toFloat() << "f" << std::endl;

}


int main(int ac, char *av[])
{
    if (ac != 2)
        std::cout << "command not found please enter the real ones" << std::endl;
    else
    {
        std::cout << std::setprecision(1) << std::fixed;
        Scalar cv(av[1]);
        charPrintable(cv);
        intPrintable(cv);
        floatPrintable(cv);

    }
}