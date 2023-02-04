#if !defined(CONTACT_HPP)
#define CONTACT_HPP

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string>
#include <iomanip>

class Contact {
    private:
        int Index_;
        std::string FirstName_;
        std::string LastName_;
        std::string NickName_;
        std::string Number_;
        std::string DarkSecret_;
        bool IsValid_;
    
    public:
        void setIdx(int in);
        void setFn(std::string fn);
        void setLn(std::string ln);
        void setNn(std::string n); 
        void setNb(std::string nb);
        void setDs(std::string ds);
        void setTr(bool b);

        int getIdx();
        std::string getFn();
        std::string getLn();
        std::string getNn();
        std::string getNb();
        std::string getDs();
        bool getTr();

        Contact();
        
        Contact(int idx, std::string fn_, std::string ln_, std::string n_, std::string nb_, std::string ds_);
        
        void    ContactDisplay();
        void    print_contact();
};

#endif // CONTACT_HPP
