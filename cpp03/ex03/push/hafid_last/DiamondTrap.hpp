#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
private:
    std::string Name_;
public:
    DiamondTrap(void);
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap& cpy);
    DiamondTrap &operator=(const DiamondTrap &target);
    ~DiamondTrap();

    // public Operator
    void attack(const std::string &target);
    void whoAmI();
};

#endif