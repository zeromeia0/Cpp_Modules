/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 23:11:50 by jeslin-tici       #+#    #+#             */
/*   Updated: 2026/03/24 09:53:04 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->fixedNumber = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& newObj)
{
	std::cout << "Copy constructor called\n";
	*this = newObj;
}

Fixed& Fixed::operator=(const Fixed& newObj)
{
	std::cout << "Copy assingment operator called\n";
	if (this != &newObj)
		this->fixedNumber = newObj.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member ftion called\n";
	return (this->fixedNumber);
}
void Fixed::setRawBits(int const raw)
{
	this->fixedNumber = raw;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}