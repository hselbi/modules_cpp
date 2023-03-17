#include "Convert.hpp"


int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cout << "Number of argument is not correct, please try again!" << std::endl;
        return 0;
    }
    Convert scalar(av[1]);
    scalar.toChar();
    scalar.toInt();
    scalar.toFloat();
    scalar.toDouble();

    return 0;
}