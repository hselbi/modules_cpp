#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat :  public Animal
{
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

#endif