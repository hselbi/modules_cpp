
#include "Contact.hpp"
#include "Phonebook.hpp"

void    add_contact(Contact cont[8], int i)
{
    cont[i].setIdx(i);

    std::string fn;
    std::cout << "Enter your first name: ";
    std::getline(std::cin, fn);
    cont[i].setFn(fn);

    std::string ln;
    std::cout << "Enter your last name: ";
    std::getline(std::cin, ln);
    cont[i].setLn(ln);

    std::string nick;
    std::cout << "Enter your nick name: ";
    std::getline(std::cin, nick);
    cont[i].setNn(nick);

    std::string num;
    while(true)
    {
        std::cout << "Enter your number: ";
        std::getline(std::cin, num);
        if((num.find_first_not_of("0123456789") == std::string::npos))
        {
            cont[i].setNb(num);
            break ;
        }
        else
        {
            std::cout << "The value " << num << " is Not all digits" << std::endl;
            std::cout << "Please try again" << std::endl;
        }
    }

    std::string ds;
    std::cout << "Enter your dark secret: ";
    std::getline(std::cin, ds);
    cont[i].setDs(ds);
    cont[i].setTr(true);
}

int main()
{
    Contact contact[8];
    int i = 0;
    std::string name;
    std::cout << "[ADD]: adding a new Contact to Phonebook" << std::endl;
    std::cout << "[SEARCH]: search for a Contact in Phonebook" << std::endl;
    std::cout << "[EXIT]: exit the program" << std::endl;
    std::cout << "ENTER A CHOICE:\t";
    while (std::getline(std::cin, name))
    {
        if (!name.compare("ADD"))
        {
            i = i % 8;
            add_contact(contact, i);
            i++;
        }
        else if (!name.compare("SEARCH"))
        {
            std::cout << "here i am in searching" << std::endl;
            preview(contact);
            choosen_one(contact);
        }
        else if (!name.compare("EXIT"))
        {
            std::cout << "here i am in exit" << std::endl;
            exit(0);
        }
        std::cout << "[ADD]: adding a new Contact to Phonebook" << std::endl;
        std::cout << "[SEARCH]: search for a Contact in Phonebook" << std::endl;
        std::cout << "[EXIT]: exit the program" << std::endl;
        std::cout << "ENTER A CHOICE:\t";
    }
    return 0;
}