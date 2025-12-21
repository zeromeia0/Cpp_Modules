/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 04:14:49 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/21 04:26:17 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	
	type = "Wrong cat";
	std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& newObj) : WrongAnimal()
{
	type = "Wrong cat";
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = newObj;
}

WrongCat& WrongCat::operator=(const WrongCat& newObj)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &newObj)
		*this = newObj;
	return (*this);
}

std::string WrongCat::getType(void)
{
	return (type);
}

void WrongCat::makeSound(void)
{
	std::cout << "Wrong meows now!\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}
