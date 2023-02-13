#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
protected:
    std::string name;
    unsigned int HitPoints;
    unsigned int EnergyPoints;
    unsigned int AttackDamage;
public:
    ClapTrap(void);
    ClapTrap(std::string _name);
    ClapTrap(const ClapTrap& cp);
    ClapTrap& operator=(const ClapTrap& cp);
    ~ClapTrap();
// public method
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif