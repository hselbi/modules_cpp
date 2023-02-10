#include <iostream>

class ClapTrap
{
private:
    int HitPoints;
    int EnergyPoints;
    int AttackDammages;

protected:
    std::string Name;
public:
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    ClapTrap(void);
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& target);
    ~ClapTrap();
    ClapTrap& operator=(const ClapTrap& target);

    int getHp(void) const {return(HitPoints);}
    unsigned int getEp(void) const {return(EnergyPoints);}
    unsigned int getAd(void) const {return(AttackDammages);}
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

/***************************************************************/

class ScavTrap: public ClapTrap{
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

    int getHp(void) const {return(_hitPoints);}
    unsigned int getEp(void) const {return(_energyPoints);}
    unsigned int getAd(void) const {return(_attackDammages);}

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

/***************************************************************/

class FragTrap: public ClapTrap{
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

    int getHp(void) const {return(_hitPoints);}
    unsigned int getEp(void) const {return(_energyPoints);}
    unsigned int getAd(void) const {return(_attackDammages);}

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

/***************************************************************/

class DiamondTrap: public FragTrap, public ScavTrap{
private:
    std::string name_;
    int hitPoints_;
    unsigned int energyPoints_;
    unsigned int attackDammage_; 
public:
    DiamondTrap(void);
    DiamondTrap(std::string name);
    ~DiamondTrap();
    DiamondTrap(const DiamondTrap& target);
    DiamondTrap& operator=(const DiamondTrap& target);

    void attack(const std::string& target);

    int getHp(void) const {return(hitPoints_);}
    unsigned int getEp(void) const {return(energyPoints_);}
    unsigned int getAd(void) const {return(attackDammage_);}

    void whoAmI();
};

DiamondTrap::DiamondTrap(void): FragTrap(), ScavTrap()
{
    ClapTrap::Name = name_ + "_clap_name";
    hitPoints_ = FragTrap::getHp();
    energyPoints_ = ScavTrap::getEp();
    attackDammage_ = FragTrap::getAd();
    std::cout << "[ DiamondTrap is created! ]" << std::endl;
}

DiamondTrap::DiamondTrap(std::string n): FragTrap(), ScavTrap()
{
    name_ = n;
    Name = name_ + "_clap_name";
    hitPoints_ = FragTrap::getHp();
    energyPoints_ = ScavTrap::getEp();
    attackDammage_ = FragTrap::getAd();
    std::cout << "[ DiamondTrap is created! ]" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "[ DiamondTrap is Destroyed! ]" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& target)
{
    name_ = target.name_;
    hitPoints_ = target.hitPoints_;
    energyPoints_ = target.energyPoints_;
    attackDammage_ = target.attackDammage_;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& target)
{
    name_ = target.name_;
    hitPoints_ = target.hitPoints_;
    energyPoints_ = target.energyPoints_;
    attackDammage_ = target.attackDammage_;
    return(*this);
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(){
    std::cout << "Well, Name is " << name_ << "and my ClapTrap is " << ClapTrap::Name << std::endl;
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