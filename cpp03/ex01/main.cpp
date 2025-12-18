/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:20:36 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/18 20:27:53 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

int main()
{
	ScavTrap keeper("Keeper");
	keeper.printInfo();
	keeper.attack("boredom");
	keeper.takeDamage(99);
	keeper.printInfo();
	ScavTrap newKeeper(keeper);
	keeper.takeDamage(1);
	newKeeper.printInfo();
	newKeeper.beRepaired(20);
	ScavTrap newestKeeper;
	newestKeeper = newKeeper;
	newestKeeper.attack("the wind");
	newKeeper.printInfo();
	newestKeeper.guardGate();
}