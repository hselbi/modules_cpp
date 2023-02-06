#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
private:
    std::string name;
    Weapon& weapon;
public:
    HumanA(void);
    HumanA(std::string _name, Weapon& _weapon);

    ~HumanA();

    void attack(void);
};


#endif