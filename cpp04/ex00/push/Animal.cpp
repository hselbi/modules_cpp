#include "Animal.hpp"

std::string Animal::getType() {
	return (type);
}

Animal::Animal()
{
    type = "none";
	std::cout << "Animal constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;

}

Animal& Animal::operator= (const Animal &target) {
	type = target.type; 
    return (*this);
};


void Animal::makeSound()
{
	std::cout <<"[none]" << std::endl;
}




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



// Dog::Dog(void) : Animal()
// {
// 	type_ = "Dog";
// 	std::cout << "[ Dog: Constructor is called ]" << std::endl;
// };

// Dog::~Dog()
// {
// 	std::cout << "[ Dog: Destructor is called ]" << std::endl;
// }

// void Dog::makeSound()
// {
// 	std::cout << "▼・ᴥ・▼ \tWoof!! \n▼・ᴥ・▼ \tWoof!!" << std::endl;
// }

// std::string Dog::getType() {
// 	return (type_);
// }



// std::string WrongAnimal::getType() {
// 	return (type_);
// }

// WrongAnimal::WrongAnimal() :type_("none_type")
// {
// 	std::cout << "WrongAnimal constructor" << std::endl;
// }

// WrongAnimal::~WrongAnimal()
// {
// 	std::cout << "WrongAnimal destructor" << std::endl;
// }

// WrongAnimal& WrongAnimal::operator= (const WrongAnimal &target) {
// 	type_ = target.type_;
// 	return (*this);
// };


// void WrongAnimal::makeSound()
// {
// 	std::cout <<"[none]" << std::endl;
// }


// WrongCat::WrongCat(void) : WrongAnimal(), type_("WrongCat")
// {
// 	std::cout << "WrongCat constructor" << std::endl;
// };

// WrongCat::~WrongCat()
// {
// 	std::cout << "WrongCat destructor" << std::endl;
// }

// void WrongCat::makeSound()
// {
// 	std::cout << "meow~~~ meow~" << std::endl;
// }

// std::string WrongCat::getType() {
// 	return (type_);
// }

