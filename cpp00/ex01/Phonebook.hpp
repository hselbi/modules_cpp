#if !defined(PHONEBOOK_HPP)
#define PHONEBOOK_HPP

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class Phonebook {
private:
    Contact cont[8];
public:
    Phonebook();
    ~Phonebook();
    
    void setIdx(int in, int i);
    void setFname(std::string fname, int i);
    void setLname(std::string lname, int i);
    void setNname(std::string nname, int i);
    void setNumb(std::string num, int i);
    void setDsecret(std::string dsecret, int i);
    void setTruth(bool b, int i);

    //getters
    int getIdx(int i);
    std::string getFname(int i);
    std::string getLname(int i);
    std::string getNname(int i);
    std::string getNumb(int i);
    std::string getDsecret(int i);
    bool getTruth(int i);

    void getPreview(int i);
    void getChoosen(int i);



};

void    preview(Phonebook &ph);
void    choosen_one(Phonebook &ph);

#endif // PHONEBOOK_HPP
