#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
    this->_hitPts = 100;
    this->_energyPts = 100;
    this->_attackDamage = 30;
    std::cout << "[ FragTrap: Default Constructor Called ]" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    this->_hitPts = 100;
    this->_energyPts = 50;
    this->_attackDamage = 20;
    std::cout << "[ FragTrap: Parameterized Constructor for" << this->_name << " Called ]" << std::endl;
}

FragTrap::FragTrap(const FragTrap &cpy): ClapTrap(cpy)
{
    std::cout << "[ FragTrap: Copy Constructor Called ]" << std::endl;

}

FragTrap &FragTrap::operator=(const FragTrap &target)
{
    std::cout << "[ FragTrap: Assignation Operator Called ]" << std::endl;

    if (this != &target)
    {
        this->_name = target._name;
        this->_hitPts = target._hitPts;
        this->_energyPts = target._energyPts;
        this->_attackDamage = target._attackDamage;
    }
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "[ FragTrap: Destructor for" << this->_name << " Called ]" << std::endl;

}

void FragTrap::highFivesGuys(void)
{
    std::cout << "[ FragTrap "<< this->_name << " is request for a High Five!! ]" << std::endl;
}