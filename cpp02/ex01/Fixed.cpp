/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 09:39:01 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/14 10:25:16 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	fixed_number = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called\n";
	fixed_number = value << bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called\n";
	fixed_number = static_cast<int>(roundf(value *(1 << bits))); //STUDY BETTER THE ROUNDF AND BITS OPERATIONS AGAIN
}

Fixed::Fixed(const Fixed& newObj)
{
	std::cout << "Copy construcor called\n";
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
	return (this->fixed_number);
}
void Fixed::setRawBits(int const raw)
{
	this->fixed_number = raw;
}

float Fixed::toFloat(void) const // study again this const after the function because wtf
{
	return (fixed_number / static_cast<float>(1 << bits)); //improve bitwise operations you dumbass
}

int Fixed::toInt(void) const
{
	return (fixed_number >> bits);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

std::ostream& operator<<(std::ostream& out, const Fixed& value) {
    out << value.toFloat();
    return out;
}