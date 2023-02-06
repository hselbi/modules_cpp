#include "Harl.hpp"

int main (int ac, char *av[])
{
    if (ac != 2)
    {
        std::cout << "Put a parameter to know what Harl is saying" << std::endl;
        return 1;
    }
    Harl dign;
    dign.complain(av[1]);
    return 0;
}