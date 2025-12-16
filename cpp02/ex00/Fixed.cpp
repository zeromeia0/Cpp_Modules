/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 23:11:50 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/16 21:09:20 by jeslin-tici      ###   ########.fr       */
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
	std::cout << "getRawBits member function called\n";
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