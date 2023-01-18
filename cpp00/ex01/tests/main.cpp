
#include "Contact.hpp"
#include "phonebook.hpp"

 void    check_len(string txt)
{
    if (txt.length() <= 10)
        std::cout << std::right << std::setw(10) << txt;
    else
    {
        txt = txt.substr(0, 9) + ".";
        std::cout << std::right << std::setw(10) << txt;
    }
}

void    Contact::ContactDisplay(){
            check_len(std::to_string(Index_));
            std::cout << "|";
            check_len(FirstName_);
            std::cout << "|";
            check_len(LastName_);
            std::cout << "|";
            check_len(NickName_);
            std::cout << "|";
            check_len(Number_);
            std::cout << "|";
            check_len(DarkSecret_);
            std::cout << std::endl;
}

// void    preview(Contact cont[8])
// {
//     std::cout << std::right << std::setw(10) << "Index";
//     std::cout << "|";
//     std::cout << std::right << std::setw(10) << "First Name";
//     std::cout << "|";
//     std::cout << std::right << std::setw(10) << "Last Name";
//     std::cout << "|";
//     std::cout << std::right << std::setw(10) << "Nick Name";
//     std::cout << "|";
//     std::cout << std::right << std::setw(10) << "Cell Phone";
//     std::cout << "|";
//     std::cout << std::right << std::setw(10) << "Dark Secret" << std::endl;

//     for (int i = 0; i < 8; i++)
//     {
//         // std::cout << cont[i].getFname();
//         cont[i].ContactDisplay();
//     }
    
// }

void    add_contact(Contact cont[8], int i)
{
    cont[i].setIdx(i);

    string fn;
    std::cout << "Enter your first name: ";
    std::getline(std::cin, fn);
    cont[i].setFn(fn);

    string ln;
    std::cout << "Enter your last name: ";
    std::getline(std::cin, ln);
    cont[i].setLn(ln);

    string nick;
    std::cout << "Enter your nick name: ";
    std::getline(std::cin, nick);
    cont[i].setNn(nick);

    string num;
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

    string ds;
    std::cout << "Enter your dark secret: ";
    std::getline(std::cin, ds);
    cont[i].setDs(ds);

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