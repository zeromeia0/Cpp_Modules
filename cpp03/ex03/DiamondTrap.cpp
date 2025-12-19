/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:59:53 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/19 21:43:59 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) 
	: ClapTrap("default_clap_name", 100, 50, 20), FragTrap(), ScavTrap(), name("Default 1")
{
	std::cout << "Diamondtrap default constructor called\n";
}
 
DiamondTrap::DiamondTrap(std::string newName) 
	: ClapTrap(newName + "_clap_name", 100, 50, 20), FragTrap(), ScavTrap(), name(newName)
{
	std::cout << "DiamondTrap named constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& newObj)
	: ClapTrap(newObj.name, newObj.healthPoints, newObj.energyPoints, newObj.attackDamage),
	FragTrap(), ScavTrap(), name(newObj.name)
{
	std::cout << "Diamond trap copy constructor called\n";
	*this = newObj;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& newObj)
{
	std::cout << "DiamondTrap copy assignment called\n";
	if (this != &newObj)
		
	{
		ClapTrap::operator=(newObj);
		name = this->name;
	}
	return (*this);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "My name is [" << name << "]\n";
	std::cout << "ClapTrap name is  [" << ClapTrap::name << "]\n";
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called\n";
}