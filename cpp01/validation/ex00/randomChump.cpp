#include "Zombie.hpp"

void    randomChamp(std::string zname)
{
    Zombie *new_zombie;
    new_zombie = newZombie(zname);
    new_zombie->announce();
    delete new_zombie;
}