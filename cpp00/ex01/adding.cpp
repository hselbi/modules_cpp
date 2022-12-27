#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using std::string;

class Contact {
    private:
        string FirstName;
        string LastName;
        string NickName;
        string Number;
    
    public:
        void    ContactDisplay(){
            std::cout << "First Name: " << FirstName << std::endl;
            std::cout << "Last Name: " << LastName << std::endl;
            std::cout << "Nick Name: " << NickName << std::endl;
            std::cout << "Number: " << Number << std::endl;
        }
        //constructor
        Contact(string fname, string lname, string nname, string num)
        {
            FirstName = fname;
            LastName = lname;
            NickName = nname;
            Number = num;
        }
        void    setFname(string name)
        {
            FirstName = name;
        }
        string getFname()
        {
            return (FirstName);
        }

        void    setLname(string name)
        {
            LastName = name;
        }
        string getLname()
        {
            return (LastName);
        }

        void    setNname(string name)
        {
            NickName = name;
        }
        string getNname()
        {
            return (NickName);
        }

        void    setName(string num)
        {
            Number = num;
        }
        string getName()
        {
            return (Number);
        }
};

int main()
{
    // Contact C[8];
    Contact C1 = Contact("hafid", "sel", "sigfaults", "0699387969");
    C1.ContactDisplay();
    Contact C2 = Contact("haf", "serl", "sigts", "0699389");
    C2.ContactDisplay();
    Contact C3 = Contact("hasdljsf", "sesdkjhsrl", "sigtsdkghss", "0699385749");
    C3.ContactDisplay();
    
}