/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:56:56 by jeslin-tici       #+#    #+#             */
/*   Updated: 2026/01/17 12:02:11 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "Default Dog constructor called\n";
}

Dog::Dog(const Dog& newObj) : Animal()
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

void Dog::makeSound() const
{
	std::cout << "Dog said au au!\n";
}

Dog::~Dog(void)
{
	std::cout << "Destructor called\n";
}