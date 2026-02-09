/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:41:06 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/21 12:43:39 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "Default animal constructor called\n";
}

AAnimal::AAnimal(const AAnimal& newObj) : type("AAnimal")
{
	std::cout << "AAnimal copy constructor called\n";
	*this = newObj;
}

AAnimal& AAnimal::operator=(const AAnimal& newObj)
{
	std::cout << "AAnimal copy assingment constructor called\n";
	if (this != &newObj)
		*this = newObj;
	return (*this);
}

std::string AAnimal::getType(void) const
{
	return (type);
}

void AAnimal::makeSound() const
{
	std::cout << "AAnimal said dingeringeding\n";
}

AAnimal::~AAnimal(void)
{
	std::cout << "Destructor called\n";
}