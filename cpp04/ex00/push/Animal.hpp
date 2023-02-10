#ifndef ANIMAL_HPP
#define ANIMAL_HPP


#include <iostream>
#include <string>

class Animal
{
public:
	// OCCP
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

class Cat :  public Animal
{
	// OCCP
public:
	Cat();
	~Cat();
	Cat(const Cat &target);
	Cat& operator=(const Cat &target);

	std::string getType();
	void makeSound();
protected:
	std::string type_;

};


// class WrongCat :  public WrongAnimal
// {
// 	// OCCP
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

// class Dog :  public Animal
// {
// 	// OCCP
// public:
// 	Dog();
// 	~Dog();
// 	Dog(const Dog &target);
// 	Dog& operator=(const Dog &target);

// 	std::string getType();
// 	void makeSound();
// protected:
// 	std::string type_;

// };

// class WrongAnimal
// {
// public:
// 	// OCCP
// 	WrongAnimal();
// 	virtual ~WrongAnimal();
// 	WrongAnimal(const WrongAnimal &target) {type_ = target.type_;};

// 	WrongAnimal& operator= (const WrongAnimal &target);

// 	void makeSound();
// 	virtual std::string getType();

// protected:
// 	std::string type_;

// private:

// };

#endif;