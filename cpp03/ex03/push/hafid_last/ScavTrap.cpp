#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
    this->_hitPts = 100;
    this->_energyPts = 50;
    this->_attackDamage = 20;
    std::cout << "[ ScavTrap: Default Constructor Called ]" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    this->_hitPts = 100;
    this->_energyPts = 50;
    this->_attackDamage = 20;
    std::cout << "[ ScavTrap: Parameterized Constructor for" << this->_name << " Called ]" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &cpy): ClapTrap(cpy)
{
    std::cout << "[ ScavTrap: Copy Constructor Called ]" << std::endl;

}

ScavTrap &ScavTrap::operator=(const ScavTrap &target)
{
    std::cout << "[ ScavTrap: Assignation Operator Called ]" << std::endl;

    if (this != &target)
    {
        this->_name = target._name;
        this->_hitPts = target._hitPts;
        this->_energyPts = target._energyPts;
        this->_attackDamage = target._attackDamage;
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "[ ScavTrap: Destructor for" << this->_name << " Called ]" << std::endl;

}

void ScavTrap::attack(const std::string &target)
{
    if (this->_energyPts > 0 && this->_hitPts > 0)
    {
        std::cout << "[ ScavTrap : " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << "points of damage! ]" << std::endl;
    }
    else if (this->_energyPts == 0)
    {
        std::cout << "[ ScavTrap : " << this->_name << " is not able to attacks " << target << ", because he has not Energy Points ]" << std::endl;
    }
    else
    {
        std::cout << "[ ScavTrap : " << this->_name << " is not able to attacks " << target << ", because he has not enough hit Points ]" << std::endl;
    }
}

void ScavTrap::guardGate(void)
{
    std::cout << "[ ScavTrap "<< this->_name << " is now in Gate keeper mode!! ]" << std::endl;
}