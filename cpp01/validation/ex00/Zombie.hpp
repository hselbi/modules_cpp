#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
class Zombie
{
private:
    std::string name;
public:
    void announce(void);

    Zombie(); // default constructor
    Zombie(std::string nz); //  
    ~Zombie(); // destructor
};



Zombie* newZombie(std::string zname);
void    randomChamp(std::string zname);

#endif