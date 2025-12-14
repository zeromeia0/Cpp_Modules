/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 23:11:50 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/13 16:39:10 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->fixed_number = 0;
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
		this->fixed_number = newObj.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->fixed_number);
}
void Fixed::setRawBits(int const raw)
{
	this->fixed_number = raw;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}