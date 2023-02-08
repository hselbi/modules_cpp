#include <iostream>
#include <string>

class Animal
{
public:
	// OCCP
	Animal();
	virtual ~Animal();
	Animal(const Animal &target);

	Animal& operator= (const Animal &target);

	virtual void makeSound();
	virtual std::string getType();

	std::string *memo_;

protected:
	std::string type_;

private:

};

std::string Animal::getType() {
	return (type_);
}

Animal::Animal() :type_("none")
{
    type_ = "none";
	std::cout << "[ Animal: Constructor is Called ]" << std::endl;
	memo_ = new std::string("none");
}

Animal::~Animal()
{
	std::cout << "[ Animal: Destructor is Called ]" << std::endl;
	delete memo_;
}

Animal::Animal(const Animal &target)
{
	type_ = target.type_;
}

Animal& Animal::operator= (const Animal &target) {
	type_ = target.type_;
	return (*this);
};


void Animal::makeSound()
{
	std::cout <<"\n[ None ~_~ ]\n" << std::endl;
}

class Brain
{
	// OCCP
public:
	Brain();
	virtual ~Brain();
	Brain(const Brain &target);
	Brain& operator=(const Brain &target);

	std::string ideas[100];
};

Brain::Brain(void)
{
	std::cout << "[ Brain: Constructor is Called ]" << std::endl;
};

Brain::~Brain()
{
	std::cout << "[ Brain: Destructor is Called ]" << std::endl;
}

Brain::Brain(const Brain &target)
{
    for (size_t i = 0; i < 100; i++)
    {
        ideas[i] = target.ideas[i];
    }
}

Brain& Brain::operator= (const Brain &target) {
    for (size_t i = 0; i < 100; i++)
    {
        ideas[i] = target.ideas[i];
    }
	return (*this);
}

class Cat : virtual public Animal
{
	// OCCP
public:
	Cat();
	virtual ~Cat();
	Cat(const Cat &target);
	Cat& operator=(const Cat &target);

	std::string getType();
	void makeSound();

private:
	Brain *brain_;

};


Cat::Cat(void) : Animal()
{
	type_ = "Cat";
	brain_ = new Brain();
	std::cout << "[ Cat: Constructor is Called ]" << std::endl;
};

Cat::~Cat()
{
	delete brain_;
	std::cout << "[ Cat: Destructor is Called ]" << std::endl;
}

// Cat::Cat(const Cat &target)
// {
// 	for (int i=0; i<100; i++)
// 	{
// 		brain_->ideas[i] = target.brain_->ideas[i];
// 	}
// 	type_ = target.type_;
// }

Cat& Cat::operator= (const Cat &target) {
	type_ = target.type_;
	for (int i=0; i<100; i++)
	{
		brain_->ideas[i] = target.brain_->ideas[i];
	}
	return (*this);
};

void Cat::makeSound()
{
	std::cout << "\n=^._.^=∫ \tMeow~~~\n=^._.^=∫ \tMeow~~~\n" << std::endl;
}

std::string Cat::getType() {
	return (type_);
}

class Dog : public Animal
{
	// OCCP
public:
	Dog();
	virtual ~Dog();
	Dog(const Dog &target);
	Dog& operator=(const Dog &target);

	std::string getType();
	void makeSound();

private:
	Brain *brain_;

};


Dog::Dog(void) : Animal()
{
	type_ = "Dog";
	brain_ = new Brain();
	std::cout << "[ Dog: Constructor is Called ]" << std::endl;
};

Dog::~Dog()
{
	delete brain_;
	std::cout << "[ Dog: Destructor is Called ]" << std::endl;
}

// Dog::Dog(const Dog &target)
// {
// 	for (int i=0; i<100; i++)
// 	{
// 		brain_->ideas[i] = target.brain_->ideas[i];
// 	}
// 	type_ = target.type_;
// }

Dog& Dog::operator= (const Dog &target) {
	type_ = target.type_;
	for (int i=0; i<100; i++)
	{
		brain_->ideas[i] = target.brain_->ideas[i];
	}
	return (*this);
};


void Dog::makeSound()
{
	std::cout << "\n▼・ᴥ・▼ \tWoof!! \n▼・ᴥ・▼ \tWoof!!\n" << std::endl;
}

std::string Dog::getType() {
	return (type_);
}


int main()
{
	Animal animal[10];
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	for (int i=0; i<10; i++)
	{
		if (i<5)
			animal[i] = *dog;
		else
			animal[i] = *cat;
	}

	// dog
	// std::cout << ">>>>>>deep copy test number > dog" << std::endl;
	// delete animal[0].memo_;
	// animal[0].memo_ = new std::string("hello");
	// std::cout << *animal[0].memo_ << std::endl;
	// std::cout << *animal[3].memo_ << std::endl;

	// // cat
	// std::cout << ">>>>>>deep copy test number > cat" << std::endl;
	// delete animal[5].memo_;
	// animal[5].memo_ = new std::string("bye");
	// std::cout << *animal[5].memo_ << std::endl;
	// std::cout << *animal[8].memo_ << std::endl;

	for (int i=0; i<10; i++)
	{
		std::cout << animal[i].getType() << std::endl;
	}

	delete dog;
	delete cat;
}
