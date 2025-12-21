/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 04:09:05 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/21 04:22:48 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("wrong default")
{
	std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& newObj) : type("wrong default")
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = newObj;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& newObj)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &newObj)
		*this = newObj;
	return (*this);
}

std::string WrongAnimal::getType(void)
{
	return (type);
}

void WrongAnimal::makeSound(void)
{
	std::cout << "Wrong animal sound, which is awful\n";	
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}
