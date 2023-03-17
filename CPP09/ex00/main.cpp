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

// int main(int ac, char *av[])
// {
//     const char *fileName="/cpp_09/data.csv";
//     std::ifstream paramFile;
//     paramFile.open(fileName);
//     std::string line;
//     std::string key;
//     double value;
//     std::map <std::string, int> params;
//     while ( paramFile >> key >> value ) 
//     {
//         std::cout << "this " << value << std::endl;
//         params[key] = value; // input them into the map 
//     }
//     paramFile.close();
//     return 0;
// } 