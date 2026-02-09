/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:56:56 by jeslin-tici       #+#    #+#             */
/*   Updated: 2026/01/17 12:01:38 by vvazzs           ###   ########.fr       */
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

void Cat::makeSound() const
{
	std::cout << "Cat said meow\n";
}

Cat::~Cat(void)
{
	std::cout << "Destructor called\n";
}