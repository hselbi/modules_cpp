#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <string>

class ClapTrap
{
public :
	ClapTrap();
	ClapTrap(std::string const _name);

	virtual ~ClapTrap();

	ClapTrap(const ClapTrap &target);

	ClapTrap &operator= (const ClapTrap &target);

	 void attack(std::string const &_target);
	 void takeDamage(unsigned int _amount);
	 void beRepaired(unsigned int _amount);
	 void printName(void);

	 int getHp(void) const;
	 unsigned int getEp(void) const;
	 unsigned int getAd(void) const;

protected:
	std::string name_;
	int hitPoint_;
	unsigned int energyPoint_;
	unsigned int attackDamage_;
};

#endif //EX00_CLAPTRAP_H
