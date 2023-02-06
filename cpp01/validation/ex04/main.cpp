#include "Replace.hpp"

int main(int ac, char *av[])
{
    // std::cout << "ac : " << ac << std::endl;
    if (ac != 4)
    {
        std::cerr << "Try to put: " << av[0] << " [filename] [which word] [with what]" << std::endl;
        return 1;
    }
    std::string fn = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    Replace::changeWord(av[1], av[2], av[3]);
    return 0;
}