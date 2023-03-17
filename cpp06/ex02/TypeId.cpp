#include "TypeId.hpp"

Base::Base(void)
{
    std::cout << "[ Base: Defaul Constructor ]" << std::endl;
}

Base::~Base()
{
   std::cout << "[ Base: Default Constructor ]" << std::endl;
}

A::A(void)
{
    std::cout << "[ A: Defaul Constructor ]" << std::endl;
}

A::~A()
{
   std::cout << "[ A: Default Constructor ]" << std::endl;
}

B::B(void)
{
    std::cout << "[ B: Defaul Constructor ]" << std::endl;
}

B::~B()
{
   std::cout << "[ B: Default Constructor ]" << std::endl;
}

C::C(void)
{
    std::cout << "[ C: Defaul Constructor ]" << std::endl;
}

C::~C()
{
   std::cout << "[ C: Default Constructor ]" << std::endl;
}

Base *generate(void)
{
    Base *rtn;

    srand((unsigned) time(NULL));
    int rd = rand() % 3;
    std::cout << "this is " << rd << " random" << std::endl;

    if (rd == 0)
        rtn = new A;
    else if (rd == 1)
        rtn = new B;
    else if (rd == 2)
        rtn = new C;
    return (rtn);
}

void identify(Base* p)
{
    try
}