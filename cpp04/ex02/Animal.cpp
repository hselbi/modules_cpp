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
    virtual void makeSound() const = 0;
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


std::string random_string(int length) {
    static std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    std::string result;
    result.reserve(length);

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        result += charset[rand() % charset.length()];
    }

    return result;
}



/*      BRAIN     */

class Brain
{
public:
    std::string ideas[100];
    Brain();
    virtual ~Brain();
    
    Brain(const Brain& br);
    Brain& operator=(const Brain& br);

    
    std::string randomStr(int length);

};

Brain::Brain()
{
    std::cout << "[ Brain: Constructor is Called ]" << std::endl;
}

// Brain::Brain(const Brain& br)
// {
    
// }

Brain& Brain::operator=(const Brain& br)
{
    for (size_t i = 0; i < 100; i++)
    {
        ideas[i] = br.ideas[i];
    }
    
    return (*this);
}

Brain::~Brain()
{
    std::cout << "[ Brain: Destructor is Called ]" << std::endl;
}

std::string Brain::randomStr(int length)
{
    static std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    std::string res;

    res.reserve(length);

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        res += charset[rand() % charset.length()];
    }
    return (res);
} 

/*      CAT     */

class Cat: public Animal
{
protected:
    std::string _type;
private:
    Brain* brain;
public:
    Cat(void);
    virtual ~Cat();
    Cat(const Cat &pussyCat);
    Cat& operator=(const Cat &pussyCat);

    virtual std::string getType(void) const;
    virtual void makeSound(void) const;
};

Cat::Cat(void)
{
    brain = new Brain();
    type = "Cat";
    std::cout << "[ Cat: Constructor is Called ]" << std::endl;
}

Cat::~Cat()
{
    delete brain;
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
private:
    Brain *brain;
public:
    Dog(void);
    virtual ~Dog();
    Dog(const Dog &doggy);
    Dog& operator=(const Dog &doggy);

    virtual std::string getType(void) const;
    virtual void makeSound(void) const;
};

Dog::Dog(void)
{
    type = "Dog";
    brain = new Brain();
    std::cout << "[ Dog: Constructor is Called ]" << std::endl;
}

// Dog::Dog(const Dog& d)
// {
//     for (size_t i = 0; i < 100; i++)
//     {
//         brain->ideas[i] = d.brain->ideas[i];
//     }
//     type_ = d.type;
// }

Dog& Dog::operator=(const Dog& d)
{
    for (size_t i = 0; i < 100; i++)
    {
        brain->ideas[i] = d.brain->ideas[i];
    }
    type = d.type_;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "[ Dog: Destructor is Called ]" << std::endl;
    delete brain;
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
    // Animal ani[10];
    // Animal* dog;
    Animal* ani[10];

    for (size_t i = 0; i < 10; i++)
    {
        if (i < 5)
            ani[i] = new Dog;
        else
            ani[i] = new Cat;
    }
    
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << ani[i]->getType() << "!" <<std::endl;
    }

    for (size_t i = 0; i < 10; i++)
    {
        delete ani[i];
    }
    
    return 0;
}

