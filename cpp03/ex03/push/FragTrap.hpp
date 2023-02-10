#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
class FragTrap: public ClapTrap
{
public:
    FragTrap(void);
    FragTrap(std::string name_);
    ~FragTrap();

    void highFivesGuys(void);
    void beRepaired(unsigned int amount);
    void takeDamage(unsigned int amount);

    unsigned int getHP() const;
    unsigned int getEP() const;
    unsigned int getAD() const;
};

#endif