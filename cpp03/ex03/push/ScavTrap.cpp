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

ScavTrap::ScavTrap(const ScavTrap& cpy)
{
    std::cout << "[ Copy Contructor from the ScavTrap ]" << std::endl;
    this->name = cpy.name;
    this->HitPoints = cpy.HitPoints;
    this->EnergyPoints = cpy.EnergyPoints;
    this->AttackDamage = cpy.AttackDamage;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& target)
{
    std::cout << "[ Assignation operator from the ScavTrap ]" << std::endl;
    if (this != &target)
    {
        this->name = target.name;
        this->HitPoints = target.HitPoints;
        this->EnergyPoints = target.EnergyPoints;
        this->AttackDamage = target.AttackDamage;
    }
    return (*this);
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

unsigned int ScavTrap::getHP(void) const
{
    return (this->HitPoints);
}

unsigned int ScavTrap::getEP(void) const
{
    return (this->EnergyPoints);
}

unsigned int ScavTrap::getAD(void) const
{
    return (this->AttackDamage);
}