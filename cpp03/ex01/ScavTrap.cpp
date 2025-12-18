/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:15:20 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/18 20:29:46 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void ScavTrap::printInfo()
{
	std::cout << "Object [" << this->name << "] has [" << this->healthPoints << "] healthPoints, [" \
		<< this->energyPoints << "] energyPoints, [" << this->attackDamage << "] attackDamage\n";
}

ScavTrap::ScavTrap(void) : ClapTrap("default", 100, 50, 20)
{
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(std::string newName) : ClapTrap(newName, 100, 50, 20)
{
	std::cout << "ScavTrap named constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& newObj) : ClapTrap(newObj)
{
	std::cout << "ScavTrap copy constructor called\n";
	*this = newObj;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& newObj)
{
	std::cout << "ScavTrap copy assignment constructor called\n";
	if (this != &newObj)
	{
		this->name = newObj.name;
		this->healthPoints = newObj.healthPoints;
		this->energyPoints = newObj.energyPoints;
		this->attackDamage = newObj.attackDamage;
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (healthPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " is dead\n";
		return ;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " is low on batteries\n";
		return ; 
	}
	energyPoints--;
	std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!\n";
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap guarding the gate or whatever\n";	
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called\n";	
}

