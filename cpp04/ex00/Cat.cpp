/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:56:56 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/22 20:00:23 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "Default Cat constructor called\n";
}

Cat::Cat(const Cat& newObj) : Animal()
{
	type = "Cat";
	std::cout << "Cat copy constructor called\n";
	*this = newObj;
}

Cat& Cat::operator=(const Cat& newObj)
{
	std::cout << "Cat copy assingment constructor called\n";
	if (this != &newObj)
		type = newObj.type;
	return (*this);
}

void Cat::makeSound()
{
	std::cout << "Cat said meow\n";
}

Cat::~Cat(void)
{
	std::cout << "Destructor called\n";
}