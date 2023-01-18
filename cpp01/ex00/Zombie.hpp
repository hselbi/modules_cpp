#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
class Zombie
{
private:
    std::string name;
public:
    void announce(void);

    Zombie();
    Zombie(std::string nz);
    ~Zombie();
};



Zombie* newZombie(std::string zname);
void    randomChamp(std::string zname);

#endif