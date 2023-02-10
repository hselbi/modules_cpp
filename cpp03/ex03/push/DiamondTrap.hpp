#ifndef  DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
// #include "ClapTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string Name_;
    // unsigned int HitPoint_;
    // unsigned int EnergyPoints_;
    // unsigned int AttackDamage_;
public:
    DiamondTrap(void);
    DiamondTrap(std::string Name_);
    DiamondTrap(const DiamondTrap& target);
    DiamondTrap &operator=(const DiamondTrap& target);
    ~DiamondTrap();

    void attack(const std::string &target);
    void whoAmI(void);
};



#endif