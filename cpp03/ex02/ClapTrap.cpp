#include <iostream>

class ClapTrap
{
private:
    std::string Name;
    int HitPoints = 10;
    int EnergyPoints = 10;
    int AttackDammages = 0;
public:
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    ClapTrap(void);
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& target);
    ~ClapTrap();
    ClapTrap& operator=(const ClapTrap& target);
};

ClapTrap::ClapTrap(void) {
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDammages = 0;
    std::cout << "[ ClapTrack is created! ]" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {

    Name = name;
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDammages = 0;
    std::cout << "[ ClapTrack " << name << " is created! ]" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "[ ClapTrack is Destroyed! ]" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& target)
{
    Name = target.Name;
    HitPoints = target.HitPoints;
    EnergyPoints = target.EnergyPoints;
    AttackDammages = target.AttackDammages;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& target)
{
    Name = target.Name;
    HitPoints = target.HitPoints;
    EnergyPoints = target.EnergyPoints;
    AttackDammages = target.AttackDammages;
    return(*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (this->HitPoints <= 0)
    {
        std::cout << "ClipTrap " << this->Name << " Can't move!" << std::endl;
        return ;
    }
    if (this->EnergyPoints == 0)
    {
        std::cout << "ClipTrap " << this->Name << " has no Energy!" << std::endl;
        return ;
    }
    EnergyPoints--;
    std::cout << this->Name << " attacks " << target << ", causing " << AttackDammages << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "this is hit point : " << HitPoints << std::endl;
    std::cout << "this is attack dammages : " << AttackDammages << std::endl;
    std::cout << "this is damage : " << amount << std::endl;
    this->HitPoints -= amount;
    this->AttackDammages += amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{

    this->HitPoints += amount;
    if (this->HitPoints > 10)
        this->HitPoints = 10;
    this->AttackDammages -= amount;
    this->EnergyPoints--;
    std::cout << "this is hit point : " << HitPoints << std::endl;
}

int main(void)
{

	ClapTrap claptrap("Slime");

	claptrap.attack("strong rabbit");
	claptrap.takeDamage(8);
	claptrap.takeDamage(3);
	claptrap.beRepaired(30);
	claptrap.attack("strong rabbit");
	return (0);
}	