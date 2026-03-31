
#include "Span.hpp"

Span::Span() : _numOfIntegers(0){}

Span::Span(unsigned int integers) : _numOfIntegers(integers) {}

Span::Span(const Span& newObj)
{
	std::cout << "Span copy constructor called" << std::endl;
	*this = newObj;
}

Span& Span::operator=(const Span& newObj)
{
	std::cout << "Span copy assignment operator called" << std::endl;
	if (this != &newObj)
		*this = newObj;
	return (*this);
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}
