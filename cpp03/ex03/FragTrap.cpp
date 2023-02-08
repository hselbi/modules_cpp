#include <iostream>

class ClapTrap
{
private:
    std::string Name;
    int HitPoints;
    int EnergyPoints;
    int AttackDammages;
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


class FragTrap: ClapTrap{
private:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDammages;
public:
    FragTrap();
    FragTrap(std::string name_);
    ~FragTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void highFivesGuys();

};

FragTrap::FragTrap(void) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDammages = 30;
    std::cout << "[ FragTrap is created! ]" << std::endl;
}

FragTrap::FragTrap(std::string name_) {
    _name = name_;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDammages = 30;
    std::cout << "[ FragTrap " << name_ << "is created! ]" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "[ FragTrap is Destroyed! ]" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "[ FragTrap gives high five. ]" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (this->_hitPoints <= 0)
    {
        std::cout << "FragTrap " << this->_name << " Can't move!" << std::endl;
        return ;
    }
    if (this->_energyPoints == 0)
    {
        std::cout << "FragTrap " << this->_name << " has no Energy!" << std::endl;
        return ;
    }
    _energyPoints--;
    std::cout << this->_name << " attacks " << target << ", causing " << _attackDammages << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
    std::cout << "this is hit point : " << _hitPoints << std::endl;
    std::cout << "this is attack dammages : " << _attackDammages << std::endl;
    std::cout << "this is damage : " << amount << std::endl;
    this->_hitPoints -= amount;
    this->_attackDammages += amount;
}

void FragTrap::beRepaired(unsigned int amount)
{

    this->_hitPoints += amount;
    if (this->_hitPoints > 100)
        this->_hitPoints = 100;
    this->_attackDammages -= amount;
    this->_energyPoints--;
    std::cout << "this is hit point : " << _hitPoints << std::endl;
}

int main(void)
{

	FragTrap ft("Slime");

	ft.attack("strong rabbit");
	ft.takeDamage(8);
	ft.takeDamage(3);
	ft.beRepaired(30);
	ft.attack("strong rabbit");
    ft.highFivesGuys();
	return (0);
}	