/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 14:21:44 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/10/07 14:21:45 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

RPN::RPN()
{
	std::cout << "Default RPN constructor called" << std::endl;
}

RPN::RPN(const RPN& newObj)
{
	std::cout << "RPN copy constructor called" << std::endl;
	*this = newObj;
}

RPN& RPN::operator=(const RPN& newObj)
{
	std::cout << "RPN copy assignment operator called" << std::endl;
	if (this != &newObj) //fix this
		*this = newObj;
	return (*this);
}

RPN::~RPN()
{
	std::cout << "RPN destructor called" << std::endl;
}
