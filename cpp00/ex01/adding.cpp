#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using std::string;

class Contact {
    private:
        int Index;
        string FirstName;
        string LastName;
        string NickName;
        string Number;
    
    public:
        void    ContactDisplay(){
            std::string fn = FirstName;
            fn.resize(10, '.');
            std::string ln = LastName;
            ln.resize(10, '.');
            std::string nn = NickName;
            nn.resize(10, '.');
            std::string nb = Number;
            nb.resize(10, '.');
            std::cout << Index << " | " << fn << " | " << ln << " | " << nn << " | " << nb << std::endl;
        }

        //constructor is special type of method that which runs everytime instantiate the object
        Contact()
        {
            Index = 0;
            FirstName = "";
            LastName = "";
            NickName = "";
            Number = "";
        }
        Contact(int i, string fname, string lname, string nname, string num)
        {
            Index = i;
            FirstName = fname;
            LastName = lname;
            NickName = nname;
            Number = num;
        }

        void    setIndex(int i)
        {
            Index = i;
        }
        
        int getIndex()
        {
            return (Index);
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
    Contact people[8] ;
    // Contact C1 = Contact("hafid", "sel", "sigfaults", "0699387969");
    // Contact people[0] = Contact("hafid", "sel", "sigfaults", "0699387969");
    // C1.ContactDisplay();
    // Contact C2 = Contact("haf", "serl", "sigts", "0699389");
    // C2.ContactDisplay();
    // Contact C3 = Contact("hasdljsf", "sesdkjhsrl", "sigtsdkghss", "0699385749");
    // C3.ContactDisplay();

    for (int i = 0; i < 8; i++)
    {
        std::cout << "************* ";
        std::cout << i+1;
        std::cout << "*************" << std::endl;
        people[i].setIndex(i);
    
        std::string fname;
        std::cout << "Enter your first name: ";
        std::cin >> fname;
        people[i].setFname(fname);
        
        std::string lname;
        std::cout << "Enter your last name: ";
        std::cin >> lname;
        people[i].setLname(lname);

        std::string nickname;
        std::cout << "Enter your nickname: ";
        std::cin >> nickname;
        people[i].setNname(nickname);

        std::string number;
        while (true)
        {
            std::cout << "Enter your number: ";
            std::cin >> number;
            if((number.find_first_not_of("0123456789") == std::string::npos))
            {
                people[i].setName(number);
                break ;
            }
            else
                std::cout<<"The value "<<number<<" is Not all digits"<<std::endl;
        }
        
    }

    for (int i = 0; i < 8; i++)
    {
        std::cout << "************* ";
        std::cout << i+1;
        std::cout << " *************" << std::endl;
        people[i].ContactDisplay();
    }
    
    
    
}