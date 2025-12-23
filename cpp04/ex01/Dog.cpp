/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:56:56 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/23 00:26:16 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal(), brain()
{
	type = "Dog";
}

Dog::Dog(const Dog& newObj) : Animal(), brain()
{
	type = "Dog";
	
	*this = newObj;
}

Brain& Dog::getBrain(void)
{
	return (brain);
}

const Brain& Dog::getBrain(void) const
{
	return (brain);
}

Dog& Dog::operator=(const Dog& newObj)
{
	if (this != &newObj)
	{
		Animal::operator=(newObj);
		brain = newObj.brain;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog said au au!\n";
}

Dog::~Dog(void) {}