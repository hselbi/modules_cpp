#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";

    std::string *stringPTR = &str;
    std::string &stringREF = str;

    // print addresses of each
    std::cout << "The memory address of `str` is => " << &str << std::endl;
    std::cout << "The memory address of `stringPTR` is => " << stringPTR << std::endl;
    std::cout << "The memory address of `stringREF` is => " << &stringREF << std::endl;

    // print values of each
    std::cout << "The value of `str` is => " << str << std::endl;
    std::cout << "The value of `stringPTR` is => " << *stringPTR << std::endl;
    std::cout << "The value of `stringREF` is => " << stringREF << std::endl;

    return 0;
}