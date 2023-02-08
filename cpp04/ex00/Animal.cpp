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



int main(void)
{
	// Animal
    Animal* meta = new Animal();
    // Animal* j = new Dog();
    Animal* i = new Cat();

    // std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); 
    // j->makeSound();
    meta->makeSound();

    delete meta;
    // delete j;
    // delete i;

	// // WrongAnimal
	// std::cout << "\n[[WrongAnimal]]" << std::endl;
	// {
	// 	WrongAnimal* meta = new WrongAnimal();
	// 	WrongAnimal* i = new WrongCat();

	// 	std::cout << i->getType() << " " << std::endl;
	// 	i->makeSound();
	// 	meta->makeSound();

	// 	delete meta;
	// 	delete i;
	// }

	return (0);
}