#include "ClapTrap.hpp"

int main()
{
    ClapTrap ct("Slime");

    ct.attack("Giant");
    ct.takeDamage(8);
    ct.takeDamage(5);
    ct.beRepaired(2);
    ct.attack("Giant");
    return 0;
}