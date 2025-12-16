/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:16:33 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/16 18:29:33 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//=====CONSTRUCTORS======

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

//=====MEMBER FUNCTIONS======

int Fixed::getRawBits(void) const
{
	return (this->fixed_number);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_number = raw;
}

float Fixed::toFloat(void) const //remember to study this const after functions shit
{
	return (fixed_number / static_cast<float>(1 << bits));
}

int Fixed::toInt(void) const
{
	return (fixed_number >> bits);
}

//=====COMPARISON OPERATOR STUFF======

bool Fixed::operator>(const Fixed& target) const
{
	return (fixed_number > this->fixed_number);
}

bool Fixed::operator<(const Fixed& target) const
{
	return (fixed_number < this->fixed_number);
}

bool Fixed::operator>=(const Fixed& target) const
{
	return (fixed_number >= this->fixed_number);
}

bool Fixed::operator<=(const Fixed& target) const
{
	return (fixed_number <= this->fixed_number);
}

bool Fixed::operator==(const Fixed& target) const
{
	return (fixed_number == this->fixed_number);
}

bool Fixed::operator!=(const Fixed& target) const
{
	return (fixed_number != this->fixed_number);
}

//=====CALCULATION OPERATORS STUFF======

Fixed Fixed::operator+(const Fixed& target) const
{
	return (this->toFloat() + target.toFloat());
}

Fixed Fixed::operator-(const Fixed& target) const
{
	return (this->toFloat() - target.toFloat());
}

Fixed Fixed::operator*(const Fixed& target) const
{
	return (this->toFloat() * target.toFloat());
}

Fixed Fixed::operator/(const Fixed& target) const
{
	return (this->toFloat() / target.toFloat());
}

Fixed& Fixed::operator++()
{
	fixed_number++;
	return *this;
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