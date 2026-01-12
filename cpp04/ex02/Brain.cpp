/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 12:44:26 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/23 00:24:01 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "Food";
}

Brain::Brain(const Brain& newObj)
{
	*this = newObj;
}

Brain& Brain::operator=(const Brain& newObj)
{
	if (this != &newObj)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = newObj.ideas[i];
	}
	return (*this);
}

std::string Brain::getIdea(int i) const
{
	if (i < 0 || i >= 100)
		return ("Invalid index\n");
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

Brain::~Brain() {}
