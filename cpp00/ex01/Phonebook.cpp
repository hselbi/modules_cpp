#include "Phonebook.hpp"
#include "Contact.hpp"
#include <strstream>
#include <sstream>
#include <cmath>

Phonebook::Phonebook() {}
Phonebook::~Phonebook() {}

// setters
void Phonebook::setIdx(int, int i) {cont[i].setIdx(i);}
void Phonebook::setFname(std::string fname, int i) {cont[i].setFn(fname);}
void Phonebook::setLname(std::string lname, int i) {cont[i].setLn(lname);}
void Phonebook::setNname(std::string nname, int i) {cont[i].setNn(nname);}
void Phonebook::setNumb(std::string num, int i) {cont[i].setNb(num);}
void Phonebook::setDsecret(std::string dsecret, int i) {cont[i].setDs(dsecret);}
void Phonebook::setTruth(bool b, int i) {cont[i].setTr(b);}

//getters
int Phonebook::getIdx(int i) {return cont[i].getIdx();}
std::string Phonebook::getFname(int i) {return cont[i].getFn();}
std::string Phonebook::getLname(int i) {return cont[i].getLn();}
std::string Phonebook::getNname(int i) {return cont[i].getNn();}
std::string Phonebook::getNumb(int i) {return cont[i].getNb();}
std::string Phonebook::getDsecret(int i) {return cont[i].getDs();}
bool Phonebook::getTruth(int i) {return cont[i].getTr();}

// get preview and choosen
void Phonebook::getPreview(int i) {cont[i].ContactDisplay();}
void Phonebook::getChoosen(int i) {cont[i].print_contact();}

// function for preview
void    preview(Phonebook &ph)
{
    std::cout << std::right << std::setw(10) << "Index";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "First Name";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Last Name";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Nick Name";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Cell Phone";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Dark Secret" << std::endl;

    std::cout << std::right << std::setw(11) << "|";
    std::cout << std::right << std::setw(11) << "|";
    std::cout << std::right << std::setw(11) << "|";
    std::cout << std::right << std::setw(11) << "|";
    std::cout << std::right << std::setw(11) << "|" << std::endl;

    for (int i = 0; i < 8; i++)
        ph.getPreview(i);
}

void    choosen_one(Phonebook &ph)
{
    std::string inp;
    std::stringstream ss;
    int    num;

    std::cout << std::endl << "choose an index from 1 to 8" << std::endl << std::endl;
    std::getline(std::cin, inp);

    if((inp.find_first_not_of("0123456789") != std::string::npos))
    {
        std::cerr << "this is not a number" << std::endl << std::endl;
        return ;
    }
    ss << inp;
    ss >> num;
    if (ss.fail())
        std::cerr << "this is not a number" << std::endl;
    else if (num >= 1 && num < 9)
        ph.getChoosen(num - 1);
    else
        std::cerr << "this is number is not between [1-8]" << std::endl;

}
