#include "Convert.hpp"


int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cout << "Number of argument is not correct, please try again!" << std::endl;
        return 0;
    }
    // std::string var(av[1]);
    // std::cout << var << std::endl;
    // try
    // {
    Convert scalar(av[1]);
    scalar.toChar();
    scalar.toInt();
    scalar.toFloat();
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
}