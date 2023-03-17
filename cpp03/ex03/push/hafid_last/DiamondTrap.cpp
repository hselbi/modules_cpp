#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("default_clap_trap")
{
    this->Name_ = "default";
    this->_hitPts = FragTrap::_hitPts;
    this->_energyPts = ScavTrap::_energyPts;
    this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &cpy): ClapTrap(cpy), ScavTrap(cpy), FragTrap(cpy)
{
    *this = cpy;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_trap")
{
    this->Name_ = name;
    this->_hitPts = FragTrap::_hitPts;
    this->_energyPts = ScavTrap::_energyPts;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "[ DiamondTrap: Copy Constructor Called ]" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &target)
{
    std::cout << "[ DiamondTrap: Assignation Operator Called ]" << std::endl;

    if (this != &target)
    {
        this->_name = target._name + "_clap_trap";
        this->_hitPts = target._hitPts;
        this->_energyPts = target._energyPts;
        this->_attackDamage = target._attackDamage;
    }
    return (*this);
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
     std::cout << "Well, Name is " << Name_ << "and my ClapTrap is " << ClapTrap::_name << std::endl;
}


DiamondTrap::~DiamondTrap()
{
        std::cout << "[ DiamondTrap: Destructor for" << this->_name << " Called ]" << std::endl;
}
