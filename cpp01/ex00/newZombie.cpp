#include "Zombie.hpp"

Zombie* newZombie(std::string zname)
{
    Zombie *new_zombie;
    
    new_zombie = new Zombie(zname);
    return new_zombie;
}