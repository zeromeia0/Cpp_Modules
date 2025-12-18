/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:33:47 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/18 20:40:08 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void FragTrap::printInfo()
{
	std::cout << "Object [" << this->name << "] has [" << this->healthPoints << "] healthPoints, [" \
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
	{
		this->name = newObj.name;
		this->healthPoints = newObj.healthPoints;
		this->energyPoints = newObj.energyPoints;
		this->attackDamage = newObj.attackDamage;
	}
	return (*this);
}

void FragTrap::attack(const std::string& target)
{
	if (healthPoints <= 0)
	{
		std::cout << "FragTrap " << name << " is dead\n";
		return ;
	}
	if (energyPoints <= 0)
	{
		std::cout << "FragTrap " << name << " is low on batteries\n";
		return ; 
	}
	energyPoints--;
	std::cout << "FragTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!\n";
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " gives you a high five!\n";	
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called\n";	
}

