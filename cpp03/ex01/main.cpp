/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:57:47 by beatde-a          #+#    #+#             */
/*   Updated: 2025/12/16 22:23:47 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap napoleon("Napoleon");
	napoleon.attack("the Russian czar");
	napoleon.attack("King of Spain");
	napoleon.attack("King of Portugal");
	napoleon.attack("King of Prussia");
	napoleon.attack("a very tall tree");
	napoleon.attack("a bowl of cereal");
	napoleon.takeDamage(8);
	napoleon.beRepaired(2);
	napoleon.attack("the invisible hand of the market");
	napoleon.attack("an old lady");
	napoleon.takeDamage(3);
	ClapTrap second(napoleon);
	napoleon.beRepaired(1);
	napoleon.attack("the sun");
	napoleon.takeDamage(2);
	napoleon.attack("Death itself");
	second.attack("Death itself");
	ClapTrap third;
	third = second;
	second.takeDamage(2);
	third.attack("no one");
}