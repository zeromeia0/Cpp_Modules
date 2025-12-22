/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 12:44:26 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/22 20:14:08 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "Food";
}

Brain::Brain(const Brain& newObj)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = newObj;
}

Brain& Brain::operator=(const Brain& newObj)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &newObj)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = newObj.ideas[i];
	}
	return (*this);
}

std::string Brain::getIdea(int i)
{
	if (i < 0 || i >= 100)
	{
		std::cout << "Invalid index\n";
		return ;
	}
	return (ideas[i]);
}

void Brain::setIdea(int i, std::string idea)
{
	if (i < 0 || i >= 100)
	{
		std::cout << "Invalid index\n";
		return ;
	}
	this->ideas[i] = idea;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
