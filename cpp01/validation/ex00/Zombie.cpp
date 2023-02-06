#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
    name = "zombie with no names";
}

Zombie::Zombie(std::string nz)
{
    name = nz;
}

Zombie::~Zombie()
{
    std::cout << "[" << name << "]: Dead" << std::endl;
}