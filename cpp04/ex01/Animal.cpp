/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:41:06 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/21 12:43:39 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Default animal constructor called\n";
}

Animal::Animal(const Animal& newObj) : type("Animal")
{
	std::cout << "Animal copy constructor called\n";
	*this = newObj;
}

Animal& Animal::operator=(const Animal& newObj)
{
	std::cout << "Animal copy assingment constructor called\n";
	if (this != &newObj)
		*this = newObj;
	return (*this);
}

std::string Animal::getType(void) const
{
	return (type);
}

void Animal::makeSound() const
{
	std::cout << "Animal said dingeringeding\n";
}

Animal::~Animal(void)
{
	std::cout << "Destructor called\n";
}