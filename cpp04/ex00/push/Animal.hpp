#ifndef ANIMAL_HPP
#define ANIMAL_HPP


#include <iostream>
#include <string>

class Animal
{
public:
	Animal();
	virtual ~Animal();
	Animal(const Animal &target) {type = target.type;};
	Animal& operator= (const Animal &target);

	virtual void makeSound();
	virtual std::string getType();

protected:
	std::string type;

private:

};





// class WrongCat :  public WrongAnimal
// {
// public:
// 	WrongCat();
// 	~WrongCat();
// 	WrongCat(const WrongCat &target);
// 	WrongCat& operator=(const WrongCat &target);

// 	std::string getType();
// 	void makeSound();
// protected:
// 	std::string type_;

// };



#endif