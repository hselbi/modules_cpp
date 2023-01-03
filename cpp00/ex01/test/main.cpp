#include "phonebook.hpp"


void    preview(Phonebook cont[8])
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
    {
        // std::cout << cont[i].getFname();
        cont[i].ContactDisplay();
    }
    
}


void contactsInput(Phonebook contact, int i)
{
    contact.setIndex(i);

    string fn;
    std::cout << "Enter your first name: ";
    std::getline(std::cin, fn);
    contact.setFname(fn);

    string ln;
    std::cout << "Enter your last name: ";
    std::getline(std::cin, ln);
    contact.setLname(ln);

    string nick;
    std::cout << "Enter your nick name: ";
    std::getline(std::cin, nick);
    contact.setNname(nick);

    string num;
    while(true)
    {
        std::cout << "Enter your number: ";
        std::getline(std::cin, num);
        if((num.find_first_not_of("0123456789") == std::string::npos))
        {
            contact.setNumber(num);
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
    contact.setDsecrest(ds);
}

int main()
{
    Phonebook contact[8];
    int i = 0;
    std::string name;
    while (std::getline(std::cin, name))
    {
        if (!name.compare("ADD"))
        {
            i = i % 8;
            contact[i].setIndex(i);

            string fn;
            std::cout << "Enter your first name: ";
            std::getline(std::cin, fn);
            contact[i].setFname(fn);

            string ln;
            std::cout << "Enter your last name: ";
            std::getline(std::cin, ln);
            contact[i].setLname(ln);

            string nick;
            std::cout << "Enter your nick name: ";
            std::getline(std::cin, nick);
            contact[i].setNname(nick);

            string num;
            while(true)
            {
                std::cout << "Enter your number: ";
                std::getline(std::cin, num);
                if((num.find_first_not_of("0123456789") == std::string::npos))
                {
                    contact[i].setNumber(num);
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
            contact[i].setDsecrest(ds);
            
            // contactsInput(contact[i], i);
            i++;
        }
        else if (!name.compare("SEARCH"))
        {
            std::cout << "here i am in searching" << std::endl;
            preview(contact);
        }
        else if (!name.compare("EXIT"))
        {
            std::cout << "here i am in exit" << std::endl;
            exit(0);
        }
    }
    return 0;
}
