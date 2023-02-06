#include "Zombie.hpp"

Zombie::Zombie(void)
{}

Zombie::Zombie(std::string zn)
{
    zname = zn;
}

Zombie::~Zombie()
{
    std::cout << "Finish Him!!!!" << std::endl;
}

void Zombie::setName(std::string zn)
{
    zname = zn;
}

void Zombie::announce(void)
{
    std::cout << zname << ": BraiiiiiiinnnzzzZ..." << std::endl;
}