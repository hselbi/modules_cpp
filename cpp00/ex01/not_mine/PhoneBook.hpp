
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string> //std::string
#include <iomanip> // set
#include <sstream> // std::stringstream


class PhoneBook
{	
    public:
        void input_contact (int _idx);

        void print_page (void) const;
        void print_column(std::string _text) const;
        void print_privew(int _index) const;

    private:
        int idx_;
        
        std::string first_name_;
        std::string last_name_;
        std::string nick_name_;
        std::string phone_number_;
        std::string darkest_secret_;
};

#endif
