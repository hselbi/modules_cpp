#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 0;
    }
    BitcoinExchange b("cpp_09/data.csv");

    b.output(av[1]);
    return 0;
} 