/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:36:41 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/19 18:08:34 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), healthPoints(10), energyPoints(10), attackDamage(10)
{
	std::cout << "Default ClapTrap created\n";
}

ClapTrap::ClapTrap(std::string newName, int healthPoints, int energyPOints, int attackDamage)
	: name(newName), healthPoints(healthPoints), energyPoints(energyPOints), attackDamage(attackDamage)
{
	std::cout << "ClapTrap parameter constructor called\n";
}

ClapTrap::ClapTrap(std::string newName) : name(newName), healthPoints(10), energyPoints(10), attackDamage(10)
{
	std::cout << "Creating ClapTrap called " << name << "\n";
}

ClapTrap::ClapTrap(const ClapTrap& newObj)
{
	std::cout << "ClapTrap Copy constructor called\n";
	*this = newObj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& newObj)
{
	std::cout << "ClapTrap Copy assingment constructor called\n";
	if (this != &newObj)
	{
		this->name = newObj.name;
		this->healthPoints = newObj.healthPoints;
		this->energyPoints = newObj.energyPoints;
		this->attackDamage = newObj.attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (healthPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is dead\n";
		return ;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is low on batteries\n";
		return ; 
	}
	energyPoints--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	healthPoints -= amount;
	if (healthPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " was killed in combat by taking " << amount << " of damage!\n";
		return ;
	}
	else
		std::cout << "ClapTrap " << name << " took " << amount << " of damage, and his current HP is " << healthPoints << "\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (healthPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is dead\n";
		return ;
	}
	
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is low on batteries\n";
		return ;
	}

	energyPoints--;
	if (healthPoints + amount >= maxHP)
	{
		healthPoints = maxHP;
		std::cout << "ClapTrap " << name << " is fully healed and ready to destroy its enemies\n";
		return ;
	}
	else
	{
		healthPoints += amount;
		std::cout << "ClapTrap " << name << " healed " << amount << " health points!\n";
	}
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called\n";
}
