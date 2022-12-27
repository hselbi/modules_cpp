#include <iostream>
#include <stdlib.h>
// #include <string>
#include <stdio.h>
#include <string.h>

/*

!You have to implement phonebook classes:
    * Stands for a phonebook contact.

*/

class Contacts
{
    private:
        std::string fname;
        std::string lname;
        std::string nname;
        std::string phone;
        std::string dsecret;

    public:
        Contacts(std::string first_name, std::string last_name, std::string nickname, 
            std::string number, std::string darkside) : 
            fname(first_name),
            lname(last_name),
            nname(nickname),
            phone(phone),
            dsecret(darkside)
        {};
        std::string    check_number(std::string phone)
        {
            std::istringstream num;
            int digit;
            while ()
            {
                if
            }
            
        }
        std::string GetFname() const {return fname;}
        std::string GetLname() const {return lname;}
        std::string GetNname() const {return nname;}
        std::string GetPhone() const {return phone;}
        std::string GetDsecret() const {return dsecret;}

};