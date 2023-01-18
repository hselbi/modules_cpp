#include <iostream>

class Weapon
{
    private:
        std::string wtype;
    public:
        void setType(std::string newType);
        std::string getType(void);
        Weapon(std::string newType);
    
};


void Weapon::setType(std::string newType)
{
    wtype = newType;

}
std::string Weapon::getType(void)
{
    return(wtype);
}


Weapon::Weapon(std::string newType)
{
    wtype = newType;
}

class HumanA {
    private:
        std::string name;
        Weapon& weapon;
    public:
        HumanA(std::string _name, Weapon& _weapon);
        void attack();
};

HumanA::HumanA(std::string _name, Weapon& _weapon) : name(_name), weapon(_weapon) {}

void HumanA::attack() 
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

class HumanB {
    private:
        std::string name;
        Weapon* weapon;
    public:
        HumanB(std::string _name);
        void setWeapon(Weapon& weapon);
        void attack(void);
        
};

HumanB::HumanB(std::string _name)
{
    name = _name;
}

void HumanB::setWeapon(Weapon& weapon) 
{ 
    this->weapon = &weapon;
}

void HumanB::attack() 
{
    if (weapon != nullptr) {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    } else {
        std::cout << name << " has no weapon to attack with" << std::endl;
    }
}

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude hafid club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}