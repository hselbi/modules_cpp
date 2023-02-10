#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
    std::string name;
    int HitPoints;
    int EnergyPoints;
    int AttackDamage;
public:
    ClapTrap(void);
    ClapTrap(std::string _name);
    ClapTrap(const ClapTrap& cp);
    ClapTrap& operator=(const ClapTrap& cp);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif