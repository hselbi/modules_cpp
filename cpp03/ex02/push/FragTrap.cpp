#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    std::cout << "[ FragTrap: Constructor Created ]" << std::endl;
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
}

FragTrap::FragTrap(std::string name_)
{
    std::cout << "[ FragTrap: Copy constructor ]" << std::endl;
    name = name_;
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "[ FragTrap: Destructor ]" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "[ FragTrap request a High Five ]" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
    HitPoints += amount;
    if (HitPoints > 100)
        HitPoints = 100;
    AttackDamage -= amount;
    if (AttackDamage < 0)
        AttackDamage = 0;
    EnergyPoints--;
}

void FragTrap::takeDamage(unsigned int amount)
{
    HitPoints -= amount;
    if (HitPoints < 0)
        HitPoints = 0;
    AttackDamage += amount;
    if (AttackDamage > 100)
        AttackDamage = 100;
}