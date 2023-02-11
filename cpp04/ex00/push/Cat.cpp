#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
    type_ = "Cat";
	std::cout << "[ Cat: Constructor is called ]" << std::endl;
};

Cat::~Cat()
{
	std::cout << "[ Cat: Destructor is called ]" << std::endl;
}

void Cat::makeSound()
{
	std::cout << "=^._.^=∫ \tMeow~~~\n=^._.^=∫ \tMeow~~~" << std::endl;
}

std::string Cat::getType() {
	return (type_);
}
