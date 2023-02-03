#include <iostream>
#include <cstdlib>

class Base
{
public:
    Base();
    virtual ~Base();
};

Base::Base()
{
    std::cout << "[ Default Constructor Called ]" << std::endl;
}

Base::~Base()
{
    std::cout << "[ Destructor Called ]" << std::endl;
}

// ? class A

class A : public Base
{
public:
    A();
    ~A();
};

A::A()
{
    std::cout << "[ A: Constructor Called ]" << std::endl;
}

A::~A()
{
    std::cout << "[ A: Destructor Called ]" << std::endl;
}

// ? class B

class B : public Base
{
public:
    B();
    ~B();
};

B::B()
{
    std::cout << "[ B: Constructor Called ]" << std::endl;
}

B::~B()
{
    std::cout << "[ B: Destructor Called ]" << std::endl;
}

// ? class C

class C : public Base
{
public:
    C();
    ~C();
};

C::C()
{
    std::cout << "[ C: Constructor Called ]" << std::endl;
}

C::~C()
{
    std::cout << "[ C: Destructor Called ]" << std::endl;
}

Base * generate(void)
{
    Base *rtn;
    
    srand((unsigned) time(NULL));
	int rd = rand() % 3;
	std::cout<<"this is " << rd<<std::endl;

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
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "c" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << &a << "A" << std::endl;    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << &b << "B" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        C& c = dynamic_cast<C&>(p);

        std::cout << &c << "C" << std::endl;    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    } 
}

int main()
{
    for(int i=0; i<3; i++)
	{
		Base *base = generate();
		identify(base);
		identify(*base);
	}
    return 0;
}
