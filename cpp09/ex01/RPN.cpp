/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 14:21:44 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/10/09 13:40:08 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"
#include <stdexcept>

RPN::RPN() : _rpnInput("Default")
{
	std::cout << "Default RPN constructor called" << std::endl;
}

RPN::RPN(std::string input) : _rpnInput(input) {}

RPN::RPN(const RPN& newObj)
{
	*this = newObj;
}

RPN& RPN::operator=(const RPN& newObj)
{
	std::cout << "RPN copy assignment operator called" << std::endl;
	if (this != &newObj)
	{
		_rpnInput = newObj._rpnInput;
		_numbers = newObj._numbers;
	}
	return (*this);
}

void RPN::parseInput()
{
    int count = 0;

    for (size_t i = 0; i < _rpnInput.size(); ++i)
    {
        if (!((_rpnInput[i] >= '0' && _rpnInput[i] <= '9') || _rpnInput[i] == '+' || _rpnInput[i] == '-' || _rpnInput[i] == '*' || _rpnInput[i] == '/' || _rpnInput[i] == ' '))
            throw std::runtime_error("Error: Invalid input [symbol]");
        if (_rpnInput[i] == ' ')
            continue;
        if (i > 0 && _rpnInput[i - 1] != ' ')
            throw std::runtime_error("Error: Invalid input [no space between elements]");
        if (_rpnInput[i] >= '0' && _rpnInput[i] <= '9')
            count++;
        else
        {
            if (count < 2)
                throw std::runtime_error("Error: Invalid RPN expression");
            count--;
        }
    }
    if (count != 1)
        {throw std::runtime_error("Error: Invalid RPN expression");}
}

void RPN::calculate()
{
    for (size_t i = 0; i < _rpnInput.size(); ++i)
    {
        if (_rpnInput[i] == ' ')
            continue;
        if (_rpnInput[i] >= '0' && _rpnInput[i] <= '9')
        {
            int number = _rpnInput[i] - '0';
            _numbers.push(number);
        }
        else
        {
            int b = _numbers.top();
            _numbers.pop();
            int a = _numbers.top();
            _numbers.pop();
            if (_rpnInput[i] == '+')
                _numbers.push(a + b);
            else if (_rpnInput[i] == '-')
                _numbers.push(a - b);
            else if (_rpnInput[i] == '*')
                _numbers.push(a * b);
            else if (_rpnInput[i] == '/')
            {
                if (b == 0)
                    throw std::runtime_error("Error: Division by zero");
                _numbers.push(a / b);
            }
        }
    }
    std::cout << _numbers.top() << std::endl;
}

RPN::~RPN() {}
