#include <iostream>

class Base
{
private:
    int age;
public:
    Base(void);
    ~Base();
    int getAge(void) {return (age);}
};

Base::Base(void)
{
    std::cout << "[ Base: constructor called ]" << std::endl;    
    age = 25;
}

Base::~Base()
{
    std::cout << "[ Base: destructor called ]" << std::endl;
}

class Derived: Base{
private:
    int age = 30;
public:
    Derived(void);
    ~Derived();
    int getAge(void){return(age);}
};

Derived::Derived(void)
{
    std::cout << "[ Derived: constructor called ]" << std::endl;
}

Derived::~Derived()
{
    std::cout << "[ Derived: destructor called ]" << std::endl;
}



int main()
{
    std::cout << "[ this is the start of program ]\n" << std::endl;  
    // Base h;
    // std::cout << "this is my age " << h.getAge() << std::endl;
    Derived d;
    std::cout << "this is my age " << d.getAge() << std::endl;

}