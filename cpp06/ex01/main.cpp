#include "Serialize.hpp"


uintptr_t serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}

int main()
{
    Data test;

    test.strData = "DumbAss";
    
    uintptr_t u;

    Data *d;

    u = serialize(&test);
    std::cout << "this is from the serialize: " << u << std::endl;

    d = deserialize(u);
    std::cout << "this is from the deserialize: " << d->strData << std::endl;
    return 0;
}