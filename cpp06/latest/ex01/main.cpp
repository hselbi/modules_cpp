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
    d = deserialize(u);
    std::cout << "this is from the Original : " << test.strData << std::endl;
    std::cout << "this is from the Serialize: " << u << std::endl;
    std::cout << "this is from the Deserialize: " << d->strData << std::endl;

    return 0;
}