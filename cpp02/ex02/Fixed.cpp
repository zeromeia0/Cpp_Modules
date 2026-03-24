/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:16:33 by jeslin-tici       #+#    #+#             */
/*   Updated: 2026/03/24 09:53:04 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//=====CONSTRUCTORS======

Fixed::Fixed(void)
{
	fixedNumber = 0;
}

Fixed::Fixed(const int value)
{
	fixedNumber = value << bits;
}

Fixed::Fixed(const float value)
{
	fixedNumber = static_cast<int>(roundf(value *(1 << bits)));
}

Fixed::Fixed(const Fixed& newObj)
{
	*this = newObj;
}

Fixed& Fixed::operator=(const Fixed& newObj)
{
	if (this != &newObj)
		this->fixedNumber = newObj.getRawBits();
	return (*this);
}

//=====MEMBER fTIONS======

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

//=====COMPARISON OPERATOR STUFF======

bool Fixed::operator>(const Fixed& target) const
{
	return (this->fixedNumber > target.fixedNumber);
}

bool Fixed::operator<(const Fixed& target) const
{
	return (this->fixedNumber < target.fixedNumber);
}

bool Fixed::operator>=(const Fixed& target) const
{
	return (this->fixedNumber >= target.fixedNumber);
}

bool Fixed::operator<=(const Fixed& target) const
{
	return (this->fixedNumber <= target.fixedNumber);
}

bool Fixed::operator==(const Fixed& target) const
{
	return (this->fixedNumber == target.fixedNumber);
}

bool Fixed::operator!=(const Fixed& target) const
{
	return (this->fixedNumber != target.fixedNumber);
}

//=====CALCULATION OPERATORS STUFF======

Fixed Fixed::operator+(const Fixed& target) const
{
	return Fixed(this->toFloat() + target.toFloat());
}

Fixed Fixed::operator-(const Fixed& target) const
{
	return Fixed(this->toFloat() - target.toFloat());
}

Fixed Fixed::operator*(const Fixed& target) const
{
	return Fixed(this->toFloat() * target.toFloat());
}

Fixed Fixed::operator/(const Fixed& target) const
{
	if (target.toFloat() != 0)
		return Fixed(this->toFloat() / target.toFloat());
	
	std::cout << "Can't divide by zero\n";
	return (Fixed(0));
}

//=====PREFOIX AND POSTFIX STUFF======

Fixed& Fixed::operator++(void)
{
	fixedNumber++;
	return *this;
}

Fixed Fixed::operator++(int n)
{
	(void)n;

	Fixed finalValue(*this);
	fixedNumber++;
	return (finalValue);
}

Fixed& Fixed::operator--(void)
{
	fixedNumber--;
	return *this;
}

Fixed Fixed::operator--(int n)
{
	(void)n;

	Fixed finalValue(*this);
	fixedNumber--;
	return (finalValue);
}

//=====MIN MAX======
Fixed& Fixed::min(Fixed& value1, Fixed& value2)
{
	if (value1.toFloat() > value2.toFloat())
		return (value2);
	return (value1);
}

const Fixed& Fixed::min(const Fixed& value1, const Fixed& value2)
{
	if (value1.toFloat() > value2.toFloat())
		return (value2);
	return (value1);
}

Fixed& Fixed::max(Fixed& value1, Fixed& value2)
{
	if (value1.toFloat() < value2.toFloat())
		return (value2);
	return (value1);
}

const Fixed& Fixed::max(const Fixed& value1, const Fixed& value2)
{
	if (value1.toFloat() < value2.toFloat())
		return (value2);
	return (value1);
}

std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
	out << value.toFloat(); //gotta use toFloat because it uses actual numbers instead of fixed point
    return out;
}

Fixed::~Fixed(void) {}
