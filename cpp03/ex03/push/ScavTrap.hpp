#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
public:
    ScavTrap(void);
    ScavTrap(std::string name_);
    ScavTrap(const ScavTrap& cpy);

    ScavTrap &operator=(const ScavTrap &target);
    ~ScavTrap();

    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void guardGate();

    unsigned int getHP(void) const;
    unsigned int getEP(void) const;
    unsigned int getAD(void) const;
};

#endif