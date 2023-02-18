#ifndef TYPEID_HPP
#define TYPEID_HPP

#include <iostream>
#include <string>
#include <unistd.h>    



class Base
{
public:
    Base(void);
    virtual~Base();
};

class A: public Base {
public:
    A();
    ~A();
};

class B: public Base {
public:
    B();
    ~B();
};

class C: public Base {
public:
    C();
    ~C();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif