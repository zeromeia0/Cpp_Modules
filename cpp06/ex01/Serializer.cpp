/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 20:38:41 by vvazzs            #+#    #+#             */
/*   Updated: 2026/03/24 09:30:21 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Default Serializer constructor called" << std::endl;
}

Serializer::Serializer(const Serializer&)
{
	std::cout << "Serializer copy constructor called" << std::endl;
}

Serializer& Serializer::operator=(const Serializer&)
{
	std::cout << "Serializer copy assignment operator called" << std::endl;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr)); // Take this pointer and treat its raw bits as an integer (uintptr_t) | Turn this pointer into a number.
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw)); //Take the address in raw and pretend it points to a Data
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor called" << std::endl;
}
