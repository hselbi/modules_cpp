#if !defined(CONTACT_HPP)
#define CONTACT_HPP

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iomanip>

using std::string;

class Contact {
    private:
        int Index_;
        string FirstName_;
        string LastName_;
        string NickName_;
        string Number_;
        string DarkSecret_;
    
    public:
        void setIdx(int in) {Index_ = in;}
        void setFn(string fn) { FirstName_ = fn;}
        void setLn(string ln) { LastName_ = ln;}
        void setNn(string n) { NickName_ = n;}
        void setNb(string nb) { Number_ = nb;}
        void setDs(string ds) { DarkSecret_ = ds;}

        int getIdx() {return Index_;}
        string getFn() { return FirstName_; }
        string getLn() { return LastName_;}
        string getNn() { return NickName_;}
        string getNb() { return Number_;}
        string getDs() { return DarkSecret_;}

        Contact()
        {
            Index_ = 0;
            FirstName_ = "";
            LastName_ = "";
            NickName_ = "";
            Number_ = "";
            DarkSecret_ = "";
        }
        
        Contact(int idx, string fn_, string ln_, string n_, string nb_, string ds_)
        {
            Index_ = idx;
            FirstName_ = fn_;
            LastName_ = ln_;
            NickName_ = n_;
            Number_ = nb_;
            DarkSecret_ = ds_;
        }
        
        void    ContactDisplay();
        void    print_contact();
};

#endif // CONTACT_HPP
