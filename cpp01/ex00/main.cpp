/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:55:44 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/01/12 13:13:38 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::cout << "\nSummoning " << ZombieOneName << "\n";
	randomChump(ZombieOneName);

	std::cout << "\n";
	
	std::cout << "\nSummoning " << ZombieTwoName << "\n";
	Zombie *zombie2 = newZombie(ZombieTwoName); //confirm if zombie2 is a 
	//												reference to ZombieTwoName, 
													//so the newZombie function 
													//creates a new or the 
													//reference creates a new one?
	if (!zombie2)
	{
		std::cout << "Couldn't create it somewhy\n";
		return (1);
	}
	zombie2->announce();
	delete(zombie2);
	std::cout << "\n";
	return (0);
}