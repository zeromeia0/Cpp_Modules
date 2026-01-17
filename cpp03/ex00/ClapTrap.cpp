/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:36:41 by jeslin-tici       #+#    #+#             */
/*   Updated: 2026/01/17 11:49:05 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Default"), hitPoints(10), energyPoints(10), attackDamage(10)
{
	std::cout << "Default ClapTrap created\n";
}

ClapTrap::ClapTrap(std::string newName) : name(newName), hitPoints(10), energyPoints(10), attackDamage(10)
{
	std::cout << "Creating ClapTrap called " << name << "\n";
}

ClapTrap::ClapTrap(const ClapTrap& newObj)
{
	std::cout << "Copy constructor called\n";
	*this = newObj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& newObj)
{
	std::cout << "Copy assingment constructor called\n";
	if (this != &newObj)
	{
		this->name = newObj.name;
		this->hitPoints = newObj.hitPoints;
		this->energyPoints = newObj.energyPoints;
		this->attackDamage = newObj.attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (hitPoints <= 0)
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
	std::cout << "ClapTrap " << this->name << " attacks [" << target << "] causing " << this->attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hitPoints -= amount;
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " was killed in combat by taking " << amount << " of damage!\n";
		return ;
	}
	else
		std::cout << "ClapTrap " << name << " took " << amount << " of damage, and his current HP is " << hitPoints << "\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0)
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
	if (hitPoints + amount >= maxHP)
	{
		hitPoints = maxHP;
		std::cout << "ClapTrap " << name << " is fully healed and ready to destroy its enemies\n";
		return ;
	}
	else
	{
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " healed " << amount << " health points! It's current hp is: " << hitPoints << "!\n";
	}
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called\n";
}