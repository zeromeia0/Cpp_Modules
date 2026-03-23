/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 20:38:41 by vvazzs            #+#    #+#             */
/*   Updated: 2026/03/23 20:38:43 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Default Serializer constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& newObj)
{
	std::cout << "Serializer copy constructor called" << std::endl;
	*this = newObj;
}

Serializer& Serializer::operator=(const Serializer& newObj)
{
	std::cout << "Serializer copy assignment operator called" << std::endl;
	if (this != &newObj)
		*this = newObj;
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor called" << std::endl;
}
