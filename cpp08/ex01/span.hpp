#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>

class Span {
private:
    std::vector<unsigned int> vec;
public:
    Span(void);
    Span(unsigned int _size);
    Span(const Span &target);
    Span &operator=(const Span &target);
    ~Span();

    void addNumber(unsigned int nbr);

    unsigned int shortestSpan();
    unsigned int longestSpan();

    unsigned int max(unsigned int nbr1, unsigned int nbr2);
    unsigned int min(unsigned int nbr1, unsigned int nbr2);

    class Range : public std::exception
    {
        public:
            const char *what(void) const throw();
    };
    
    class Exist : public std::exception
    {
        public:
            const char *what(void) const throw();
    };

    class Size:public std::exception
    {
        public:
            const char *what(void) const throw();
    };

    template <typename T>
    void rangeIterator(T begin, T end)
    {
        if (std::distance(begin, end) > static_cast<int>(vec.capacity() - vec.size()))
            throw Size();
        std::cout << "this is distance " << std::distance(begin, end) << std::endl;
        std::cout << "this is size " << vec.size() << std::endl;
        std::cout << "this is capacity " << vec.capacity() << std::endl;
        
        while (begin != end)
            vec.push_back(*begin++);
    }

};

#endif