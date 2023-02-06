#include "Weapon.hpp"

Weapon::Weapon(std::string t)
{
    type = t;
}

Weapon::~Weapon()
{}

void Weapon::setType(std::string ty)
{
    type = ty;
}

std::string Weapon::getType(void) const
{
    return type;
}