#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

class Replace
{
public:
    Replace(void);
    ~Replace();
    static void changeWord(const std::string& fn, const std::string& s1, const std::string& s2);
};


#endif