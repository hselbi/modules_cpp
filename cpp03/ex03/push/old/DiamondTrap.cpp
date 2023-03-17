#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap("Default")
{
    std::cout << "[ DiamondTrap: Constructor Called ]" << std::endl;
    // ClapTrap::name = Name_ + "_clap_name";
    HitPoint_ = FragTrap::getHP();
    EnergyPoints_ = ScavTrap::getEP();
    AttackDamage_ = FragTrap::getAD();
}

DiamondTrap::DiamondTrap(std::string nm): ClapTrap(nm + "_clap_name")
{

    std::cout << "[ DiamondTrap: Constructor Called ]" << std::endl;
    Name_ = nm;
    ClapTrap::name = nm + "_clap_name";
    this->HitPoints = FragTrap::getHP();
    this->EnergyPoints = ScavTrap::getEP();
    this. = FragTrap::getAD();
}

DiamondTrap::DiamondTrap(const DiamondTrap& target)
{
    Name_ = target.Name_;
    HitPoint_ = target.HitPoint_;
    EnergyPoints_ = target.EnergyPoints_;
    AttackDamage_ = target.AttackDamage_;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& target)
{
    if (this != &target)
    {
        Name_ = target.Name_;
        HitPoint_ = target.HitPoint_;
        EnergyPoints_ = target.EnergyPoints_;
        AttackDamage_ = target.AttackDamage_;
    }
    return (*this);
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "[ DiamondTrap: Destructor Called ]" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
     std::cout << "Well, Name is " << Name_ << "and my ClapTrap is " << ClapTrap::name << std::endl;
}