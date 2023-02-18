#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>
#include <typeinfo>
#include <limits>
#include <cctype>
#include <cmath>
#include <cfloat>
#include <sstream>
#include <iomanip>

class Convert
{
private:
    static std::string strInt;
    static double value;
    static bool _cannot;
    static bool _isChar;
public:
    Convert(void);
    Convert(char *_inp);
    Convert(const Convert &target);
    Convert &operator=(const Convert &target);
    ~Convert();


    static void toChar(void);
    static void toInt(void);
    static void toFloat(void);
    static void toDouble(void);
};

#endif