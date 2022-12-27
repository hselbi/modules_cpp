//need to done this by adding the contact and the searching for about the things that i register in it

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iomanip>

void    Phonebook::print_str(std::string _s) const
{
    if (_s.length() <= 10)
        std::cout << std::right << std::setw(10) << _s;
    else{
        _s = _s.substr(0, 9) + ".";
        std::cout << std::right << std::setw(10) << _s;

    }
}

void    Phonebook::display_contact(int _ind) const
{
    print_str(std::to_string(_ind));
    std::cout << "|";
    print_str();

}

void    display_preview(phonebook Obj[8])
{
    std::cout << std::right << std::setw(10) << "index";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "First Name";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Last Name";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Nickname";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Cell Phone";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Secret";
    std::cout << std::endl;

    for (int i = 0; i < 8; i++)
    {
        Obj[i].display_contact(i);
    }
}