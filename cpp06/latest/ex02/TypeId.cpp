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
    if (dynamic_cast<A*>(p))
        std::cout << "[ A ]" << std::endl;
    else if (dynamic_cast<B*>(p)) {
        std::cout << "HELLO" << std::endl;
        std::cout << "[ B ]" << std::endl;
    }
    else if (dynamic_cast<C*>(p)) {
        std::cout << "HELLO" << std::endl;
        std::cout << "[ C ]" << std::endl;
    }
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "[ A ]: " << &a << std::endl;
    }
    catch(const std::exception& e)
    {
        try
        {
            B& b = dynamic_cast<B&>(p);
            std::cout << "[ B ]: " << &b << std::endl;
        }
        catch(const std::exception& e)
        {
            try
            {
                C& c = dynamic_cast<C&>(p);
                std::cout << "[ C ]: " << &c << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
}