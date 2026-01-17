/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:33:47 by jeslin-tici       #+#    #+#             */
/*   Updated: 2026/01/17 11:49:05 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void FragTrap::printInfo()
{
	std::cout << "Object [" << this->name << "] has [" << this->hitPoints << "] hitPoints, [" \
		<< this->energyPoints << "] energyPoints, [" << this->attackDamage << "] attackDamage\n";
}

FragTrap::FragTrap(void) : ClapTrap("default", 100, 100, 30)
{
	std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(std::string newName) : ClapTrap(newName, 100, 100, 30)
{
	std::cout << "FragTrap named constructor called\n";
}

FragTrap::FragTrap(const FragTrap& newObj) : ClapTrap(newObj)
{
	std::cout << "FragTrap copy constructor called\n";
	*this = newObj;
}

FragTrap& FragTrap::operator=(const FragTrap& newObj)
{
	std::cout << "FragTrap copy assignment constructor called\n";
	if (this != &newObj)
		ClapTrap::operator=(newObj);
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " gives you a high five!\n";	
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called\n";	
}

