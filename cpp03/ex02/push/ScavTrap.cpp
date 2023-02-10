#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    std::cout << "[ Contructor from the ScavTrap ]" << std::endl;
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
}

ScavTrap::ScavTrap(std::string name_)
{
    std::cout << "[ Contructor parameterized from the ScavTrap ]" << std::endl;
    name = name_;
    HitPoints = 100;
    EnergyPoints = 20;
    AttackDamage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "[ Destructor called from ScavTrap ]" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "[ ScavTrap is now in Gate keeper mode ]" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    HitPoints += amount;
    if (HitPoints > 100)
        HitPoints = 100;
    AttackDamage -= amount;
    if (AttackDamage < 0)
        AttackDamage = 0;
    EnergyPoints--;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    HitPoints -= amount;
    if (HitPoints < 0)
        HitPoints = 0;
    AttackDamage += amount;
    if (AttackDamage > 100)
        AttackDamage = 100;
}