/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:38:08 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/19 18:10:10 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap coolGuy("Cool Guy");
	coolGuy.printInfo();
	coolGuy.attack("lameness");
	coolGuy.takeDamage(99);
	coolGuy.printInfo();

	FragTrap cloning("cloning");
	FragTrap newCoolGuy(cloning);
	newCoolGuy.printInfo();
	coolGuy.takeDamage(1);
	newCoolGuy.beRepaired(20);
	
	FragTrap newestCoolGuy;
	newCoolGuy.printInfo();
	newestCoolGuy = newCoolGuy;
	newestCoolGuy.attack("outdated fashion trends");
	newestCoolGuy.highFivesGuys();
}