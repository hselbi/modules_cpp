#include "Span.hpp"

Span::Span(void)
{}

Span::Span(unsigned int size)
{
    vec.reserve(size);
}

Span::Span(const Span &target)
{
    vec.reserve(target.vec.size());
    std::copy(target.vec.begin(), target.vec.end(), vec.begin());
}

Span &Span::operator=(const Span &target)
{
    vec.clear();
    vec.reserve(target.vec.size());
    std::copy(target.vec.begin(), target.vec.end(), vec.begin());
    return (*this);
}

Span::~Span() {
    vec.clear();
}

unsigned int Span::max(unsigned int nbr1, unsigned int nbr2)
{
    if (nbr1 > nbr2)
        return nbr1;
    else
        return nbr2;
}

unsigned int Span::min(unsigned int nbr1, unsigned int nbr2)
{
    if (nbr1 > nbr2)
        return nbr2;
    else
        return nbr1;
}

void Span::addNumber(unsigned int nbr)
{
    if (vec.size() == vec.capacity())
        throw Size();
    std::vector<unsigned int>::iterator it;
    it = std::find(vec.begin(), vec.end(), nbr);
    vec.begin();
    if (it != vec.end())
        throw Exist();
    vec.push_back(nbr);
}

unsigned int Span::shortestSpan(void)
{
    if (vec.size() <= 1)
        throw Range();
    unsigned int shortRange = 0;
    for(std::vector<unsigned int>::iterator it = vec.begin(); it+1 != vec.end(); it++)
    {
        if (!shortRange || max(*it, *(it + 1)) - min(*it, *(it + 1)) < shortRange)
            shortRange = max(*it, *(it + 1)) - min(*it, *(it + 1));
    }
    return shortRange;
}

unsigned int Span::longestSpan(void)
{
    if (vec.size() <= 1)
        throw Range();
    unsigned int longRange = 0;
    for(std::vector<unsigned int>::iterator it = vec.begin(); it+1 != vec.end(); it++)
    {
        if (max(*it, *(it + 1)) - min(*it, *(it + 1)) > longRange)
            longRange = max(*it, *(it + 1)) - min(*it, *(it + 1));
    }
    return longRange;
}

const char *Span::Exist::what() const throw() {
    return ("it's already existing !!!");
}

const char *Span::Size::what() const throw() {
    return ("Size is Full !!!");
}

const char *Span::Range::what() const throw() {
    return ("There's no Range !!!");
}