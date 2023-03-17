#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
public:
    FragTrap(void);
    FragTrap(std::string name);
    FragTrap(const FragTrap &cpy);
    FragTrap &operator=(const FragTrap &target);
    ~FragTrap();

    // public method

    void highFivesGuys(void);
};

#endif