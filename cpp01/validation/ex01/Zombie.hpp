#if !defined(ZOMBIE_HPP)
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
    std::string zname;
public:
    Zombie(void);
    Zombie(std::string zn);
    ~Zombie();

    void announce(void);
    void setName(std::string zn);
};

Zombie* zombieHorde( int N, std::string name );

#endif // ZOMBIE_HPP
