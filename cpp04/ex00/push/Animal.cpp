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
	std::cout <<"** Unknow **" << std::endl;
}




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

