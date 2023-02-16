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
    std::string strInt;
    double value;
    bool _cannot;
public:
    Convert(void);
    Convert(char *_inp);
    Convert(const Convert &target);
    Convert &operator=(const Convert &target);


    void toChar(void);
    void toInt(void);
    void toFloat(void);
    void toDouble(void);
};

#endif