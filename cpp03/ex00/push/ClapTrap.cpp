#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "[ Default Constructor Called ]" << std::endl;
}

ClapTrap::ClapTrap(std::string _name)
{
    std::cout << "[ Constructor Parameterized Called ]" << std::endl;
    name = _name;
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& cp)
{
    std::cout << "[ Copy Constructor Called ]" << std::endl;
    this->name = cp.name;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& cp)
{
    std::cout << "[ Copy Assignement Operator Called ]" << std::endl;
    if (this != &cp)
        this->name = cp.name;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "[ Destructor Called ]" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    // std::cout << "|****************** Take Damage **********************|" << std::endl;
    // std::cout << "Hit Point: " << HitPoints << std::endl;
    // std::cout << "Attack Dammages: " << AttackDamage << std::endl;
    // std::cout << "Damages: " << amount << std::endl;

    this->HitPoints -= amount;
    if (HitPoints < 0)
        this->HitPoints = 0;
    this->AttackDamage += amount;
    if (AttackDamage > 10)
        this->AttackDamage = 10;

    // std::cout << "after ==> Attack Dammages: " << AttackDamage << std::endl;
    // std::cout << "after ==> Hit Point: " << HitPoints << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (HitPoints <= 0)
    {
        std::cout << "ClipTrap " << name << " Can't move!" << std::endl;
        return ;
    }
    if (EnergyPoints == 0)
    {
        std::cout << "ClipTrap " << name << " Has no Energy!!" << std::endl;
        return ;
    }
    EnergyPoints--;
    std::cout << name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "Hit Point :" << HitPoints << std::endl;
    std::cout << "amount :" << amount << std::endl;
    HitPoints += amount;
    if (HitPoints > 10)
        HitPoints = 10;
    AttackDamage -= amount;
    if (AttackDamage < 0)
        AttackDamage = 0;
    EnergyPoints--;
    std::cout << "amount :" << amount << std::endl;
    std::cout << "Hit Point :" << HitPoints << std::endl;
}