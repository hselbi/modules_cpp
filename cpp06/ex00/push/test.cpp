#include <iostream>
#include <string>
#include <sstream>

bool isNumeric(std::string str) {
    std::istringstream iss(str);
    double d;
    char c;
    if (!(iss >> d) || (iss >> c)) {
        return false;
    }
    return true;
}

int main(int ac, char *av[]) {
    if (ac != 2)
    {
        std::cout << "this is false" << std::endl;
        return 0;
    }
    std::string str1(av[1]);

    std::cout << std::boolalpha;
    std::cout << isNumeric(str1) << std::endl;
    return 0;
}