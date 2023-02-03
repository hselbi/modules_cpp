#include <iostream>
#include <string>
#include <typeinfo>
#include <limits>
#include <cfloat>
#include <math.h>
#include <cctype>

/*
* first  i need to check if parameter that i passed is a string or a float or int or double
* then make this type as the original type then convert it to other types that lefts
*/

class convert
{
private:
    std::string strIn;
    double val;
    bool _cannot;
public:
    convert(void);
    ~convert();
    convert(char *_inp);
    convert(const convert &tar);
    convert &operator=(const convert &tar);


    void toChar(void);
    void toInt(void);
    void toFloat(void);
    void toDouble(void);
};

convert::convert(void) : _cannot(false)
{
    std::cout << "[ Constructer Called ]" << std::endl;
}

convert::convert(char *_inp)  
{
    _cannot = false;
    val = 0.0;
    // std::cout << _cannot  << std::endl;
    strIn = static_cast<std::string>(_inp);
    // std::cout << val << std::endl;
    // std::cout << _inp << std::endl;
    try
    {
        val = std::stod(_inp);
    }
    catch(...)
    {
        _cannot = true;
    }
    std::cout << val << std::endl;
    
}
convert::convert(const convert &tar)
{
    strIn = tar.strIn;
}

convert &convert::operator=(const convert &tar)
{
    strIn = tar.strIn;
    return (*this);
}

convert::~convert()
{
    std::cout << "[ Destructor Called ]" << std::endl; 
}

void convert::toInt(void)
{
    std::cout << "int : ";
    if (_cannot == true || std::isnan(val) || val > INT32_MAX)
        std::cout << "Impossible" << std::endl;
    else
        std::cout << static_cast<int>(val) << std::endl;
}

void convert::toFloat(void)
{
    std::cout << "float: ";
    if (_cannot == true || std::isnan(val) || val > FLT_MAX)
        std::cout << "nanf" << std::endl;
    else
        std::cout << static_cast<float>(val) << "0f" <<std::endl;
}

void convert::toDouble(void)
{
    std::cout << "double: ";
    if (_cannot == true || std::isnan(val) || val > DBL_MAX)
        std::cout << "nan" << std::endl;
    else
        std::cout << static_cast<double>(val) << std::endl;
}

int main (int ac, char *av[])
{
    if (ac != 2)
    {
        std::cout << "Number of argument is not correct, please try again!" << std::endl;
        return 0;
    }
    std::string target(av[1]);
    // std::cout << target << " : " << typeid(target).name() << std::endl;
    convert cv(av[1]);

    cv.toInt();
    cv.toFloat();
    cv.toDouble();
}