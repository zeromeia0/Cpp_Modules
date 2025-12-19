/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:38:08 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/19 21:43:17 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap frankie("Frankie");
	frankie.attack("their own reflection in the mirror");
	frankie.takeDamage(99);
	DiamondTrap newFrankie(frankie);
	frankie.takeDamage(1);
	newFrankie.beRepaired(20);
	DiamondTrap newestFrankie;
	newestFrankie = newFrankie;
	newestFrankie.attack("their parents");
	newestFrankie.guardGate();
	newestFrankie.highFivesGuys();
	newestFrankie.whoAmI();
}