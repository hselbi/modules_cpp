#include "Phonebook.hpp"
#include "Contact.hpp"
#include <strstream>
#include <sstream>
#include <iostream>
#include <cmath>

void    preview(Contact cont[8])
{
    std::cout << std::right << std::setw(10) << "Index";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "First Name";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Last Name";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Nick Name";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Cell Phone";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Dark Secret" << std::endl;

    std::cout << std::right << std::setw(11) << "|";
    std::cout << std::right << std::setw(11) << "|";
    std::cout << std::right << std::setw(11) << "|";
    std::cout << std::right << std::setw(11) << "|";
    std::cout << std::right << std::setw(11) << "|" << std::endl;

    for (int i = 0; i < 8; i++)
        cont[i].ContactDisplay();
    
}

void    choosen_one(Contact cont[8])
{
    std::string inp;
    std::stringstream ss;
    int    num;

    std::cout << std::endl << "choose an index from 1 to 10" << std::endl;
    std::getline(std::cin, inp);

    if((inp.find_first_not_of("0123456789") != std::string::npos))
    {
        std::cerr << "this is not a number" << std::endl << std::endl;
        return ;
    }
    ss << inp;
    ss >> num;
    if (ss.fail())
        std::cerr << "this is not a number" << std::endl;
    else if (num >= 1 && num < 9)
        cont[num - 1].print_contact();
    else
        std::cerr << "this is number is not between [1-8]" << std::endl;

}