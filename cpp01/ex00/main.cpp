/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:55:44 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/01/13 18:11:09 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::cout << "\nSummoning " << ZombieOneName << "\n";
	randomChump(ZombieOneName);

	std::cout << "\n";
	
	std::cout << "\nSummoning " << ZombieTwoName << "\n";
	Zombie *zombie2 = newZombie(ZombieTwoName); //new Zombie object is created on the heap
														// using newZombie(), that return a 
														// zombie* (address to the object)
														//zombie 2 is a local pointer variable
//zombie 2 is pointint to a new zombie that was created with the newZombie() fuinction
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