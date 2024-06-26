#include <iostream>

class Zombie
{
    private:
        std::string zname;
    public:
        void set_name(std::string name);
        void announce(void);
        ~Zombie();
};

void Zombie::set_name(std::string name)
{
    zname = name;
}

Zombie::~Zombie()
{
    std::cout << zname << ": death" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << zname << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* zombieHorde( int N, std::string name)
{
    if (N <= 0)
        return (NULL);
    Zombie* hordeZombies = new Zombie[N];

    for (int i = 0; i < N; i++)
        hordeZombies[i].set_name(name);
    return (hordeZombies);
}

int main()
{
    Zombie* hordes;
    int c = 12;

    hordes = zombieHorde(c, "hafid");
    for (int i = 0; i < c; i++)
        hordes->announce();

    delete[] hordes;
    system("leaks a.out");
    return 0;
}
