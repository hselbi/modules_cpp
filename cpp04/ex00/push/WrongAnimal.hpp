#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
public:
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(const WrongAnimal &target);

	WrongAnimal& operator= (const WrongAnimal &target);

	void makeSound();
	virtual std::string getType();

protected:
	std::string type_;

};

#endif