/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 01:17:18 by vvazzs            #+#    #+#             */
/*   Updated: 2026/06/02 05:42:49 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0){}

Span::Span(unsigned int integers) : _maxSize(integers) {}

Span::Span(const Span& newObj)
{
	*this = newObj;
}

Span& Span::operator=(const Span& newObj)
{
	if (this != &newObj)
	{
        this->_maxSize = newObj._maxSize;
		this->_numbers = newObj._numbers;
	}
	return (*this);
}

const char* Span::SpanFullException::what() const throw()
{
    return ("[Span is full]");    
}

void Span::addNumber(int n)
{
    try
    {
        if (_numbers.size() >= _maxSize)
            throw (SpanFullException());
        _numbers.push_back(n);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

int Span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw (std::runtime_error("Not enough elements"));
    std::vector<int> temp = _numbers;
    std::sort(temp.begin(), temp.end());
    int minSpan = temp[1] - temp[0];
    for (size_t i = 1; i < temp.size() - 1; i++)
	{
        int diff = temp[i + 1] - temp[i];
        if (diff < minSpan)
            minSpan = diff;
    }
    return (minSpan);
}

int Span::longestSpan() {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough elements");
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return (max - min);
}

Span::~Span() {}
