
#include "Contact.hpp"
#include "Phonebook.hpp"

void    add_contact(Phonebook &ph, int i)
{
    std::string digits = "0123456789";
    std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    ph.setIdx(i, i);

    // first name
    std::string fn;
    std::cout << "Enter your first name: ";
    while(std::getline(std::cin, fn))
    {
        if(!fn.empty() &&(fn.find_first_not_of(characters) == std::string::npos))
        {
            ph.setFname(fn, i);
            break ;
        }
        else
        {
            std::cout << "The value " << fn << " is Not a String" << std::endl;
            std::cout << "Please try again" << std::endl;
            std::cout << "Enter your first name: ";
        }
    }

    if (std::cin.eof()==1) 
    {
        std::cin.clear();
        std::cin.ignore();
        exit (1);
    }

    // last name
    std::string ln;
    std::cout << "Enter your last name: ";
    while(std::getline(std::cin, ln))
    {
        if(!ln.empty() &&(ln.find_first_not_of(characters) == std::string::npos))
        {
            ph.setLname(ln, i);
            break ;
        }
        else
        {
            std::cout << "The value " << fn << " is Not a String" << std::endl;
            std::cout << "Please try again" << std::endl;
            std::cout << "Enter your last name: ";
        }
    }
    if (std::cin.eof()==1) 
    {
        std::cin.clear();
        std::cin.ignore();
        exit (1);
    }

    // nick_name
    std::string nick;
    std::cout << "Enter your nick name: ";
    while(std::getline(std::cin, nick))
    {
        if(!nick.empty() &&(nick.find_first_not_of(characters) == std::string::npos))
        {
            ph.setNname(nick, i);
            break ;
        }
        else
        {
            std::cout << "The value " << fn << " is Not a String" << std::endl;
            std::cout << "Please try again" << std::endl;
            std::cout << "Enter your nick name: ";
        }
    }
    if (std::cin.eof()==1) 
    {
        std::cin.clear();
        std::cin.ignore();
        exit (1);
    }

    // number
    std::string num;
    std::cout << "Enter your number: ";
    while(std::getline(std::cin, num))
    {
        if(!num.empty() && (num.find_first_not_of("0123456789") == std::string::npos))
        {
            ph.setNumb(num, i);
            break ;
        }
        else
        {
            std::cout << "The value " << num << " is Not all digits" << std::endl;
            std::cout << "Please try again" << std::endl;
            std::cout << "Enter your number: ";
        }
    }
    if (std::cin.eof()==1) 
    {
        std::cin.clear();
        std::cin.ignore();
        exit (1);
    }
    // dark secret
    std::string ds;
    std::cout << "Enter your dark secret: ";
    while(std::getline(std::cin, ds))
    {
        if(!ds.empty() && (ds.find_first_not_of(characters) == std::string::npos))
        {
            ph.setDsecret(ds, i);
            break ;
        }
        else
        {
            std::cout << "The value " << fn << " is Not a String" << std::endl;
            std::cout << "Please try again" << std::endl;
            std::cout << "Enter your dark secret: ";
        }
    }
    if (std::cin.eof()==1) 
    {
        std::cin.clear();
        std::cin.ignore();
        exit (1);
    }
    ph.setTruth(true, i);
}

int main()
{
    Phonebook ph;
    int i = 0;
    std::string cmd;
    std::cout << "[ADD]: adding a new Contact to Phonebook" << std::endl;
    std::cout << "[SEARCH]: search for a Contact in Phonebook" << std::endl;
    std::cout << "[EXIT]: exit the program" << std::endl << std::endl;
    std::cout << "ENTER A CHOICE:\t";
    while (std::getline(std::cin, cmd))
    {
        cmd.erase(remove(cmd.begin(), cmd.end(), ' '), cmd.end());        
        if (!cmd.compare("ADD"))
        {
            std::cout << std::endl;
            i = i % 8;
            add_contact(ph, i);
            i++;
            std::cout << std::endl;
        }
        else if (!cmd.compare("SEARCH"))
        {
            std::cout << std::endl;
            preview(ph);
            choosen_one(ph);
        }
        else if (!cmd.compare("EXIT"))
        {
            std::cout << std::endl;
            exit(0);
        }
        std::cout << "[ADD]: adding a new Contact to Phonebook" << std::endl;
        std::cout << "[SEARCH]: search for a Contact in Phonebook" << std::endl;
        std::cout << "[EXIT]: exit the program" << std::endl << std::endl;
        std::cout << "ENTER A CHOICE:\t";
    }
    return 0;
}