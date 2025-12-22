/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:56:56 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/22 20:24:33 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal(), Brain()
{
	type = "Dog";
	std::cout << "Default Dog constructor called\n";
}

Dog::Dog(const Dog& newObj) : Animal(), Brain(newObj.brain)
{
	type = "Dog";
	
	std::cout << "Dog copy constructor called\n";
	*this = newObj;
}

Dog& Dog::operator=(const Dog& newObj)
{
	std::cout << "Dog copy assingment constructor called\n";
	if (this != &newObj)
		*this = newObj;
	return (*this);
}

void Dog::makeSound()
{
	std::cout << "Dog said au au!\n";
}

Dog::~Dog(void)
{
	std::cout << "Destructor called\n";
}