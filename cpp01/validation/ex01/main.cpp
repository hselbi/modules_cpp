#include "Zombie.hpp"

int main()
{
    Zombie* zomHordes;
    int num = 0;

    zomHordes = zombieHorde(num, "Ghoul");
    for (int i = 0; i < num; i++)
    {
        zomHordes->announce();
    }
    delete[] zomHordes;
    system("leaks Moar_brainz");
    return 0;
}