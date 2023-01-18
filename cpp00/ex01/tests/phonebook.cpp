#include "phonebook.hpp"
#include "Contact.hpp"

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

    for (int i = 0; i < 8; i++)
        cont[i].ContactDisplay();
    
}

void    Contact::print_contact(void)
{
    std::cout << "First Name: " << FirstName_ << std::endl;
    std::cout << "Last Name: " << LastName_ << std::endl;
    std::cout << "Nick Name: " << NickName_ << std::endl;
    std::cout << "Number: " << Number_ << std::endl;
    std::cout << "dark Secret: " << DarkSecret_ << std::endl;
}

void    choosen_one(Contact cont[8])
{
    string inp;
    std::stringstream sstream;
    int    num;


    std::cout << "choose an index from 1 to 10" << std::endl;
    std::getline(std::cin, inp);
    sstream << inp;
    sstream >> num;

    if (sstream.fail())
        std::cerr << "this is not a number" << std::endl;
    else if (num >= 1 && num < 9)
        cont[num - 1].print_contact();
    else
        std::cerr << "this is number is not between [1-8]" << std::endl;

}