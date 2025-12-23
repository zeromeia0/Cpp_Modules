/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:56:56 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/22 23:27:21 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat() : Animal(), brain()
{
	type = "Cat";
}

Cat::Cat(const Cat& newObj) : Animal(), brain()
{
	type = "Cat";
	*this = newObj;
}

const Brain& Cat::getBrain() const
{
	return brain;
}

Cat& Cat::operator=(const Cat& newObj)
{
	if (this != &newObj)
	{
		Animal::operator=(newObj);
		brain = newObj.brain;
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat said meow\n";
}

Cat::~Cat(void) {}