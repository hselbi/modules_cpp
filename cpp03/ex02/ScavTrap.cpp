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


class ScavTrap: ClapTrap{
private:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDammages;
public:
    ScavTrap();
    ScavTrap(std::string name_);
    ~ScavTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void guardGate();

};

ScavTrap::ScavTrap(void) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDammages = 20;
    std::cout << "[ ScavTrap is created! ]" << std::endl;
}

ScavTrap::ScavTrap(std::string name_) {
    _name = name_;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDammages = 20;
    std::cout << "[ ScavTrap " << name_ << "is created! ]" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "[ ScavTrap is Destroyed! ]" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "[ ScavTrap is now in Gate keeper mode. ]" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_hitPoints <= 0)
    {
        std::cout << "ScavTrap " << this->_name << " Can't move!" << std::endl;
        return ;
    }
    if (this->_energyPoints == 0)
    {
        std::cout << "ScavTrap " << this->_name << " has no Energy!" << std::endl;
        return ;
    }
    _energyPoints--;
    std::cout << this->_name << " attacks " << target << ", causing " << _attackDammages << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    std::cout << "this is hit point : " << _hitPoints << std::endl;
    std::cout << "this is attack dammages : " << _attackDammages << std::endl;
    std::cout << "this is damage : " << amount << std::endl;
    this->_hitPoints -= amount;
    this->_attackDammages += amount;
}

void ScavTrap::beRepaired(unsigned int amount)
{

    this->_hitPoints += amount;
    if (this->_hitPoints > 10)
        this->_hitPoints = 10;
    this->_attackDammages -= amount;
    this->_energyPoints--;
    std::cout << "this is hit point : " << _hitPoints << std::endl;
}

int main(void)
{

	ScavTrap st("Slime");

	st.attack("strong rabbit");
	st.takeDamage(8);
	st.takeDamage(3);
	st.beRepaired(30);
	st.attack("strong rabbit");
    st.guardGate();
	return (0);
}	