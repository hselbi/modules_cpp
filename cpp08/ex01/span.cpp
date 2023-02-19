#include "span.hpp"

Span::Span(unsigned int _size)
{
	numbers_.reserve(_size);
}

Span::~Span()
{
	numbers_.clear();
}

Span::Span(const Span &target)
{
	numbers_.clear();
	numbers_.reserve(target.numbers_.size());
	std::copy(target.numbers_.begin(), target.numbers_.end(), numbers_.begin());
}

Span &Span::operator=(const Span &target)
{
	numbers_.clear();
	numbers_.reserve(target.numbers_.size());
	std::copy(target.numbers_.begin(), target.numbers_.end(), numbers_.begin());
	return (*this);
}


void Span::addNumber(unsigned int _number)
{
	// Size chek
	if (numbers_.size() == numbers_.capacity())
		throw SizeOver();

	// Same number check
	std::vector<unsigned int>::iterator iter;
	iter = std::find (numbers_.begin(), numbers_.end(), _number);
	numbers_.begin();
	if (iter != numbers_.end())
		throw ExistNumber();

	// OK!
	numbers_.push_back(_number);
}

unsigned int Span::min(unsigned int _n1, unsigned int _n2)
{
	if (_n1 < _n2)
		return (_n1);
	else
		return (_n2);
}

unsigned int Span::max(unsigned int _n1, unsigned int _n2)
{
	if (_n1 < _n2)
		return (_n2);
	else
		return (_n1);
}


unsigned int Span::shortestSpan(void) 
{
	if (numbers_.size() <= 2)
		throw NoRange();
	unsigned int shortRange = 0;
	for (std::vector<unsigned int>::iterator itr = numbers_.begin(); itr+1 != numbers_.end(); ++itr)
	{
		if (shortRange == 0 || (*itr, *(itr+1)) - min(*itr, *(itr+1)) < shortRange)
			shortRange = max(*itr, *(itr+1)) - min(*itr, *(itr+1));
	}
	return (shortRange);
}

unsigned int Span::longestSpan(void)	
{
	if (numbers_.size() <= 2)
		throw NoRange();
	unsigned int longRange = 0;
	for (std::vector<unsigned int>::iterator itr = numbers_.begin(); itr+1 != numbers_.end(); ++itr)
	{
		if (max(*itr, *(itr+1)) - min(*itr, *(itr+1)) > longRange)
			longRange = max(*itr, *(itr+1)) - min(*itr, *(itr+1));
	}

	return (longRange);
}

const char* Span::SizeOver::what() const throw()
{
	return ("Size over!!!");
}

const char* Span::ExistNumber::what() const throw()
{
	return ("Existing Number!!");
}

const char* Span::NoRange::what() const throw()
{
	return ("No range!");
}
