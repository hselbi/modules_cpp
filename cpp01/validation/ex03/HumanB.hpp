#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon* weapon;
public:
    HumanB(std::string _name);
    ~HumanB();
    void setWeapon(Weapon& firearm);
    void attack(void);
};

#endif