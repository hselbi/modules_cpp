#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	type_ = "Dog";
	std::cout << "[ Dog: Constructor is called ]" << std::endl;
};

Dog::~Dog()
{
	std::cout << "[ Dog: Destructor is called ]" << std::endl;
}

void Dog::makeSound()
{
	std::cout << "▼・ᴥ・▼ \tWoof!! \n▼・ᴥ・▼ \tWoof!!" << std::endl;
}

std::string Dog::getType() {
	return (type_);
}

// Dog::~Dog()
// {

// }