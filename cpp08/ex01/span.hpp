#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
public:
	Span();
	Span(unsigned int _size);
	virtual ~Span();
	Span(const Span &target);
	Span &operator=(const Span &target);


	void addNumber(unsigned int _number);

	unsigned int shortestSpan();
	unsigned int longestSpan();

	class ExistNumber : public std::exception {
	public:
		const char *what(void) const throw();
	};

	class SizeOver : public std::exception {
	public:
		const char *what(void) const throw();
	};

	class NoRange : public std::exception {
	public:
		const char *what(void) const throw();
	};

	unsigned int min(unsigned int _n1, unsigned _n2);
	unsigned int max(unsigned int _n1, unsigned _n2);

private:
	std::vector<unsigned int> numbers_;

};


#endif
