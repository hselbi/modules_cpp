#ifndef ANIMAL_CPP
#define ANIMAL_CPP

#include <iostream>
#include <string>


class Animal
{
private:
    std::string _type;
public:
    Animal(void);
    Animal(const Animal &target);
    Animal& operator=(const Animal &target);
    virtual void makeSound();
    virtual std::string getType();

    std::string *memo_;
    ~Animal();
};

#endif