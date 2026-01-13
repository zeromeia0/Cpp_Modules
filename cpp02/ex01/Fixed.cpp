/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 09:39:01 by jeslin-tici       #+#    #+#             */
/*   Updated: 2026/01/13 18:21:47 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	fixedNumber = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called\n";
	fixedNumber = value << bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called\n";
	fixedNumber = static_cast<int>(roundf(value *(1 << bits))); //rounf rounds float to nearest int value
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
		this->fixedNumber = newObj.getRawBits(); //study shallow and deep copy
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->fixedNumber);
}
void Fixed::setRawBits(int const raw)
{
	this->fixedNumber = raw;
}

float Fixed::toFloat(void) const
{
	return (fixedNumber / static_cast<float>(1 << bits));
}

int Fixed::toInt(void) const
{
	return (fixedNumber >> bits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
	out << value.toFloat(); //gotta use toFloat because it uses actual numbers instead of fixed point
    return out;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}