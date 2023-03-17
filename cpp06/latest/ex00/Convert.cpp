#include "Convert.hpp"

std::string Convert::strInt = "";
double Convert::value = 0.0;
bool Convert::_cannot = false;
bool Convert::_isChar = false;
Convert::Convert(void)
{
}

Convert::Convert(char *_inp)
{

    strInt = static_cast<std::string>(_inp);
    char *ptr = NULL;

    try
    {
        if (!atoi(_inp))
            _isChar = true;
        *(const_cast<double*>(&value)) = std::strtod(_inp, &ptr);
        if (value == 0.0 && strInt[0] != '-' && strInt[0] != '+' && !std::isdigit(_inp[0]))
            throw std::invalid_argument("received inexpected argument!");
    }
    catch(const std::exception& e)
    {
        _cannot = true;
    }
    
}

Convert::Convert(const Convert &target)
{
    strInt = target.strInt;
    value = target.value;
    _cannot = target._cannot;
}

Convert &Convert::operator=(const Convert &target)
{
    if (this != &target)
    {
        strInt = target.strInt;
        value = target.value;
        _cannot = target._cannot;
    }
    return (*this);
}

Convert::~Convert()
{
}

void Convert::toInt(void)
{
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) || value > INT32_MAX)
    {
        std::cout << "Impossible " << std::endl;
    }
    else if (_isChar && strInt.length() == 1)
    {
        char x = strInt.at(0);
        std::cout << (int)x << std::endl;
    }
    else
    {
        std::cout << static_cast<int>(value) << std::endl;
    }
}

void Convert::toChar(void)
{
    char ch = static_cast<char>(value);
    std::cout << "char: ";
    if ((!_isChar && strInt.length() > 1) || std::isnan(value) || std::isinf(value))
    {
        std::cout << _cannot << std::endl;
        std::cout << "Impossible" << std::endl;
    }
    else if (_isChar && strInt.length() == 1)
    {
        std::cout << "'" << strInt << "'" << std::endl;
    }
    else if (std::isprint(ch))
        std::cout << "'" << ch << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

void Convert::toFloat(void)
{
    float f = static_cast<float>(value);
    std::cout << "float: ";
    if (std::isnan(value) || std::isinf(value))
    {
        std::cout << "nanf" << std::endl;
    }
    else if (_isChar && strInt.length() == 1)
    {
        // true is char
        char x = strInt.at(0);
        std::cout << (float)x << ".0f" << std::endl;
    }
    else if (f == static_cast<int64_t>(f))
    {
        std::cout << f << ".0f" << std::endl;
    }
    else
    {
        std::cout << std::setprecision(std::numeric_limits<float>::digits10) << f << "f" << std::endl;
    } 
}

void Convert::toDouble(void)
{
    std::cout << "Double: ";
    if (std::isnan(value) || std::isinf(value))
    {
        std::cout << "nanf" << std::endl;
    }
    else if (_isChar && strInt.length() == 1)
    {
        // true is char
        char x = strInt.at(0);
        std::cout << (float)x << ".0" << std::endl;
    }
    else if (value == static_cast<int64_t>(value))
    {
        std::cout << value << ".0" << std::endl;
    }
    else
    {
        std::cout << std::setprecision(std::numeric_limits<double>::digits10) << value << std::endl;
    } 
}