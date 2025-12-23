/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:41:06 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/22 23:27:52 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "string"

Animal::Animal() : type("Animal") {}

Animal::Animal(const Animal& newObj) : type("Animal")
{
	*this = newObj;
}

Animal& Animal::operator=(const Animal& newObj)
{
	if (this != &newObj)
		type = newObj.type;
	return (*this);
}

std::string Animal::getType(void) const
{
	return (type);
}

void Animal::makeSound(void) const
{
	std::cout << "Animal said dingeringeding\n";
}

Animal::~Animal(void) {}