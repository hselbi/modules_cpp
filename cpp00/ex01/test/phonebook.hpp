#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iomanip>

using std::string;

class Phonebook {
    private:
        int Index;
        string FirstName;
        string LastName;
        string NickName;
        string Number;
        string DarkSecret;

    public:
        // void contact_in(int in);
        // set and get index of contact
        void setIndex(int i)
        {
            Index = i;
        }
        int setIndex()
        {
            return (Index);
        }

        // set and get for first name
        void setFname(string fname)
        {
            FirstName = fname;
        }
        string getFname()
        {
            return (FirstName);
        }

        // set and get for last name
        void setLname(string lname)
        {
            LastName = lname;
        }
        string getLname()
        {
            return (LastName);
        }

        // set and get for nickname name
        void setNname(string nname)
        {
            NickName = nname;
        }
        string getNname()
        {
            return (NickName);
        }

        // set and get for number
        void setNumber(string num)
        {
            Number = num;
        }
        string getNumber()
        {
            return (Number);
        }

        // set and get for dark secret
        void setDsecrest(string dsecret)
        {
            DarkSecret = dsecret;
        }
        string getDsecret()
        {
            return (DarkSecret);
        }

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
        void    ContactDisplay(){
            check_len(std::to_string(Index));
            std::cout << "|";
            check_len(FirstName);
            std::cout << "|";
            check_len(LastName);
            std::cout << "|";
            check_len(NickName);
            std::cout << "|";
            check_len(Number);
            std::cout << "|";
            check_len(DarkSecret);
            std::cout << std::endl;
            // string fn = FirstName;
            // fn.resize(10, '.');
            // string ln = LastName;
            // ln.resize(10, '.');
            // string nn = NickName;
            // nn.resize(10, '.');
            // string nb = Number;
            // nb.resize(10, '.');
            // string ds = DarkSecret;
            // ds.resize(10, '.');

            // std::cout << Index << " | " << fn << " | " << ln << " | " << nn << " | " << nb << " | " << ds << std::endl;
        }
};

void    preview(Phonebook cont[8]);


// void Phonebook::contact_input (int ind);

#endif // PHONEBOOK_HPP
