#include <iostream>

int main()
{
    // char *txt = "HI THIS IS BRAIN";
    std::string str = "HI THIS IS BRAIN";

    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "address of the string: " << &str << std::endl;
    std::cout << "stringPTR address: " << stringPTR << std::endl;
    std::cout << "stringREF address: " << &stringREF << std::endl;
    std::cout << "stringREF pointer: " << stringREF << std::endl;

    stringREF = "hey hafid";
    
    std::cout << "Value of the string: " << str << std::endl;
    std::cout << "stringPTR pointer: " << *stringPTR << std::endl;
    std::cout << "stringREF pointer: " << stringREF << std::endl;

    
    return 0;
}
