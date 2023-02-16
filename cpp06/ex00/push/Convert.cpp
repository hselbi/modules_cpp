#include "Convert.hpp"

Convert::Convert(void): _cannot(false)
{
    std::cout << "[ Default Constructor ]" << std::endl;
}

bool isNumeric(std::string str) {
    std::istringstream iss(str);
    double d;
    char c;
    if (!(iss >> d) || (iss >> c)) {
        return false;
    }
    return true;
}

Convert::Convert(char *_inp)
{
    _cannot = true;
    value = 0.0;
    strInt = static_cast<std::string>(_inp);
    if (isNumeric(strInt))
    {
        std::cout << "stats: " << strInt << std::endl;
        try
        {
            _cannot = false;
            std::cout << "test 00" << std::endl;
            value = std::stod(_inp);
        }
        catch (...)
        {
            std::cout << "test 22" << std::endl;
            _cannot = true;
        }
    }
    std::cout << "stats: " << value << std::endl;
    std::cout << "true or false: " << _cannot << std::endl;
}

Convert::Convert(const Convert &target)
{
    strInt = target.strInt;
}

Convert &Convert::operator=(const Convert &target)
{
    if (this != &target)
        strInt = target.strInt;
    return (*this);
}

void Convert::toInt(void)
{
    std::cout << "int: ";
    if (_cannot || std::isnan(value) || value > INT32_MAX)
        std::cout << "Impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
}

void Convert::toChar(void)
{
    char ch = static_cast<char>(value);
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value))
        std::cout << "Impossible" << std::endl;
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
        // std::cout << "this is an error!! 11" << std::endl;
        std::cout << "nanf" << std::endl;
    }
    else if (f == static_cast<int64_t>(f))
    {
        // std::cout << "this is an error!! 22" << std::endl;
        std::cout << static_cast<int64_t>(f) << std::endl;
    }
    else
    {
        std::cout << value << "this is an error!! 33" << std::endl;
        std::cout << std::setprecision(std::numeric_limits<float>::digits10) << f << "f" << std::endl;
    } 
}