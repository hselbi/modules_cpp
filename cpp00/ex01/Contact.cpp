#include "Contact.hpp"

void    check_len(std::string txt)
{
    if (txt.length() <= 10)
        std::cout << std::right << std::setw(10) << txt;
    else
    {
        txt = txt.substr(0, 9) + ".";
        std::cout << std::right << std::setw(10) << txt;
    }
}

Contact::Contact()
{
    IsValid_ = false;
    Index_ = 0 + 1;
    FirstName_ = "";
    LastName_ = "";
    NickName_ = "";
    Number_ = "";
    DarkSecret_ = "";
}

<<<<<<< HEAD
Contact::~Contact() {}

Contact::Contact(int idx, std::string fn_, std::string ln_, std::string n_, std::string nb_, std::string ds_)
{
    IsValid_ = true;
    Index_ = idx;
=======
Contact::Contact(int idx, std::string fn_, std::string ln_, std::string n_, std::string nb_, std::string ds_)
{
    IsValid_ = true;
    Index_ = idx + 1;
>>>>>>> 3f0fbdffc8eec61c732b8a52f63a5927ed0fdc52
    FirstName_ = fn_;
    LastName_ = ln_;
    NickName_ = n_;
    Number_ = nb_;
    DarkSecret_ = ds_;
}

<<<<<<< HEAD
void Contact::setIdx(int in) { Index_ = in;}
=======
void Contact::setIdx(int in) {Index_ = in;}
>>>>>>> 3f0fbdffc8eec61c732b8a52f63a5927ed0fdc52
void Contact::setFn(std::string fn) { FirstName_ = fn;}
void Contact::setLn(std::string ln) { LastName_ = ln;}
void Contact::setNn(std::string n) { NickName_ = n;}
void Contact::setNb(std::string nb) { Number_ = nb;}
void Contact::setDs(std::string ds) { DarkSecret_ = ds;}
void Contact::setTr(bool b) { IsValid_ = b;}

<<<<<<< HEAD

int Contact::getIdx() { return Index_;}
=======
int Contact::getIdx() {return Index_;}
>>>>>>> 3f0fbdffc8eec61c732b8a52f63a5927ed0fdc52
std::string Contact::getFn() { return FirstName_; }
std::string Contact::getLn() { return LastName_;}
std::string Contact::getNn() { return NickName_;}
std::string Contact::getNb() { return Number_;}
std::string Contact::getDs() { return DarkSecret_;}
bool Contact::getTr() { return IsValid_;}

void    Contact::print_contact(void)
{
    if (IsValid_ == true)
    {
        std::cout << "First Name: " << FirstName_ << std::endl;
        std::cout << "Last Name: " << LastName_ << std::endl;
        std::cout << "Nick Name: " << NickName_ << std::endl;
        std::cout << "Number: " << Number_ << std::endl;
        std::cout << "dark Secret: " << DarkSecret_ << std::endl << std::endl;
    }
}

void    Contact::ContactDisplay()
{
    if (IsValid_ == true)
    {
        check_len(std::to_string(Index_ + 1));
        std::cout << "|";
        check_len(FirstName_);
        std::cout << "|";
        check_len(LastName_);
        std::cout << "|";
        check_len(NickName_);
        std::cout << "|";
        check_len(Number_);
        std::cout << "|";
        check_len(DarkSecret_);
        std::cout << std::endl;
    }
}