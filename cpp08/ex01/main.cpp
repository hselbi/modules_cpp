#include "Span.hpp"




void simple_test(void)
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void notEnough(void)
{
    try {
            Span sp = Span(1);
            sp.addNumber(211);
            sp.addNumber(2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void noRange(void)
{
    try
    {
        Span sp = Span(10);
        sp.addNumber(12);
        sp.addNumber(112);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void addRange()
{
    int arr[11] = {814, 323, 42, 860, 133, 285, 193, 15, 118, 546, 788};

    Span sp(10);
    std::cout << "0 hellow world!" << std::endl;
    sp.rangeIterator(std::begin(arr), std::end(arr));
    std::cout << "1 hellow world!" << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << "2 hellow world!" << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
}



int main() {

    std::cout << "/************* normal test *************/" << std::endl;
    simple_test();
    std::cout << "/************* size test *************/" << std::endl;
    notEnough();
    std::cout << "/************* range test *************/" << std::endl;
    noRange();
    std::cout << "/************* next level test *************/" << std::endl;
    addRange();
    return 0; 
}
