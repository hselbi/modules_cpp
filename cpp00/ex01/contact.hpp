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
        Contacts(){};
        std::string GetFname(){return fname;}
        std::string GetLname(){return lname;}
        std::string GetNname(){return nname;}
        std::string GetPhone(){return phone;}
        std::string GetDsecret() {return dsecret;}

};