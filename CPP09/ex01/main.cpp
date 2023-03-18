#include "RPN.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cout << "Usage: ./RPN \"Calculation\"" << std::endl;
        return 1;
    }
    RPN pol;
    pol.polishCalculator(av[1]);
    return 0;
}