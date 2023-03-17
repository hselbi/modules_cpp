#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"), _hitPts(10), _energyPts(10), _attackDamage(0)
{
    std::cout << "[ ClapTrap: Default Constructor Called ]" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPts(10), _energyPts(10), _attackDamage(0)
{
    std::cout << "[ ClapTrap: Parameterized Constructor for" << this->_name << " Called ]" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cpy)
{
    std::cout << "[ ClapTrap: Copy Constructor Called ]" << std::endl;

    this->_name = cpy._name;
    this->_hitPts = cpy._hitPts;
    this->_energyPts = cpy._energyPts;
    this->_attackDamage = cpy._attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &target)
{
    std::cout << "[ ClapTrap: Assignation Operator Called ]" << std::endl;

    if (this != &target)
    {
        this->_name = target._name;
        this->_hitPts = target._hitPts;
        this->_energyPts = target._energyPts;
        this->_attackDamage = target._attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "[ ClapTrap: Destructor for" << this->_name << " Called ]" << std::endl;

}

void ClapTrap::attack(const std::string &target)
{
    if (this->_energyPts > 0 && this->_hitPts > 0)
    {
        std::cout << "[ ClapTrap : " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << "points of damage! ]" << std::endl;
    }
    else if (this->_energyPts == 0)
    {
        std::cout << "[ ClapTrap : " << this->_name << " is not able to attacks " << target << ", because he has not Energy Points ]" << std::endl;
    }
    else
    {
        std::cout << "[ ClapTrap : " << this->_name << " is not able to attacks " << target << ", because he has not enough hit Points ]" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPts == 0)
    {
        std::cout << "[ ClapTrap " << this->_name << " is already dead, stop beating his ass!! ]" << std::endl;
        return ;
    }

    this->_hitPts -= amount;
    if (this->_hitPts < 0)
        this->_hitPts = 0;
    this->_attackDamage += amount;
    if (this->_attackDamage > 10)
        this->_attackDamage = 10;
    
    std::cout << "[ ClapTrap " << this->_name << " was attacked and lost " << amount << " Hit Points, now he has " << this->_hitPts << "Hit Points!!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPts > 0 && this->_hitPts > 0)
    {
        this->_hitPts += amount;
        if (this->_hitPts > 10)
            this->_hitPts = 10;
        std::cout << "[ ClapTrap: " << this->_name << " repaired itself and gained " << amount << " of Hit Points, now it's " << this->_hitPts << "hit points." << std::endl;
        this->_energyPts -= 1;
    }
    else if (this->_energyPts == 0)
    {
        std::cout << "[ ClapTrap: " << this->_name << "is not able to heal itself, because there's no more Energy Points!!" << std::endl;
    }
    else if (this->_hitPts == 0)
    {
        std::cout << "[ ClapTrap: " << this->_name << "is not able to heal itself, because he's already DEAD!!" << std::endl;
    }
}