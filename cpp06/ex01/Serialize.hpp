#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>

struct Data
{
    std::string strData;
};

uintptr_t serialize(Data* ptr);

Data* deserialize(uintptr_t raw);

#endif