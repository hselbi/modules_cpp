#include <iostream>
#include <string>

/*      ANIMALS     */

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal &ani);
    Animal &operator=(const Animal &ani);
    virtual ~Animal();

    virtual std::string getType() const;
    virtual void makeSound() const;
};

Animal::Animal()
{
    type = "none";
    std::cout << "[ Animal: Constructor is Called ]" << std::endl;
}

Animal::Animal(const Animal &ani)
{
    type = ani.type;
}

Animal::~Animal()
{
    std::cout << "[ Animal: Destructor is Called ]" << std::endl;
}

Animal &Animal::operator=(const Animal &ani)
{
    type = ani.type;
    return(*this);
}

void Animal::makeSound(void) const
{
    std::cout << "\n[ None ~_~ ]\n" << std::endl;
}

std::string Animal::getType(void) const
{
    return (type);
}

/*      CAT     */

class Cat: public Animal
{
protected:
    std::string _type;
public:
    Cat(void);
    Cat(const Cat &pussyCat);
    Cat& operator=(const Cat &pussyCat);
    virtual ~Cat();

    virtual std::string getType(void) const;
    virtual void makeSound(void) const;
};

Cat::Cat(void)
{
    _type = "Cat";
    std::cout << "[ Cat: Constructor is Called ]" << std::endl;
}

Cat::~Cat()
{
    std::cout << "[ Cat: Destructor is Called ]" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "\n=^._.^=∫ \tMeow~~~\n=^._.^=∫ \tMeow~~~\n" << std::endl;
}

std::string Cat::getType() const
{
    return (_type);
}

/*      DOG      */

class Dog: public Animal
{
protected:
    std::string type_;
public:
    Dog(void);
    Dog(const Dog &doggy);
    Dog& operator=(const Dog &doggy);
    virtual ~Dog();

    virtual std::string getType(void) const;
    virtual void makeSound(void) const;
};

Dog::Dog(void)
{
    type_ = "Dog";
    std::cout << "[ Dog: Constructor is Called ]" << std::endl;
}

Dog::~Dog()
{
    std::cout << "[ Dog: Destructor is Called ]" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "\n▼・ᴥ・▼ \tWoof!! \n▼・ᴥ・▼ \tWoof!!\n" << std::endl;
}

std::string Dog::getType() const
{
    return (type_);
}

/*      WRONG ANIMALS     */

class WrongAnimal
{
private:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &ani);
    WrongAnimal& operator=(const WrongAnimal& ani);
    virtual ~WrongAnimal();

    virtual void makeSound(void) const;
    virtual std::string getType(void) const;
};

WrongAnimal::WrongAnimal()
{
    type = "Unknown";
    std::cout << "[ WrongAnimal: Constructor is Called ]" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ani)
{
    type = ani.getType();
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& ani)
{
    type = ani.type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "[ WrongAnimal: Destructor is Called ]" << std::endl;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "\n(U・x・U)\n" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (type);
}

/*      WRONG CAT     */

class WrongCat: public WrongAnimal
{
protected:
    std::string _type;
public:
    WrongCat(void);
    WrongCat(const WrongCat &pussy);
    WrongCat& operator=(const WrongCat &pussy);
    virtual ~WrongCat();

    virtual std::string getType(void) const;
    virtual void makeSound(void) const;
};

WrongCat::WrongCat(void)
{
    _type = "WrongCat";
    std::cout << "[ WrongCat: Constructor is Called ]" << std::endl;
}

// WrongCat::WrongCat(const WrongCat& pussy)
// {
//     _type = pussy.getType();
// }

WrongCat::~WrongCat()
{
    std::cout << "[ WrongCat: Destructor is Called ]" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "\n=^._.^=∫ \tMeow~~~\n=^._.^=∫ \tMeow~~~\n" << std::endl;
}

std::string WrongCat::getType() const
{
    return (_type);
}


int main()
{
    std::cout << "/************************Animal*************************/" << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* c = new Cat();
        const Animal* d = new Dog();

        std::cout << "this is the type of animal : " << d->getType() << " " << std::endl;
        std::cout << "this is the type of animal : " << c->getType() << " " << std::endl;

        d->makeSound();
        c->makeSound();
        meta->makeSound();
        delete d;
        delete c;
        delete meta;
    }

    std::cout << "/************************non-Animal*************************/" << std::endl;
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* wcat = new WrongCat();

        std::cout << "this is the type of animal : \t" << wcat->getType() << " " << std::endl;
        wcat->makeSound();
        meta->makeSound();
        
        delete wcat;
        delete meta;

    }

    return 0;
}

