#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string _name)
{
    name = _name;
}

void HumanB::setWeapon(Weapon& firearm)
{
    this->weapon = &firearm;
}

HumanB::~HumanB()
{}

void HumanB::attack()
{
    if (weapon != nullptr)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout  << name << " no weapon means no attacks" << std::endl;
}