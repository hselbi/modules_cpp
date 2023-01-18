#include <iostream>

class Zombie
{
private:
    std::string zname;
public:
    Zombie(std::string zom_name);
    ~Zombie();
    void announce( void );
    
};

// constructor
Zombie::Zombie(std::string zom_name)
{
    zname = zom_name;
}

// destructor
Zombie::~Zombie()
{
    std::cout << "Zombie in Destructor" << std::endl;
}

// print
void Zombie::announce(void)
{
    std::cout << "<" << zname << ">: BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie( std::string name )
{
    Zombie* new_zombie;
    new_zombie = new Zombie(name);
    return (new_zombie);

}

void randomChump( std::string name )
{
    Zombie* n_zombie;
    n_zombie = newZombie(name);
    n_zombie->announce();
    delete n_zombie;
}

int main()
{
    std::string name;
    std::cout << "name of zombie: ";
    std::cin >> name;
    randomChump(name);
    return 0;
}