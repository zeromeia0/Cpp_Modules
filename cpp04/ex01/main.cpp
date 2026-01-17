/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 23:04:48 by jeslin-tici       #+#    #+#             */
/*   Updated: 2026/01/17 12:14:46 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void)
{
	Animal* bicho[10];
	int max = 5;

	for (int i = 0; i < max / 2; i++)
		bicho[i] = new Cat();
	for (int i = max / 2; i < max; i++)
		bicho[i] = new Dog();

	for (int i = 0; i < max; i++)
	{
		std::cout << bicho[i]->getType() << std::endl;
		bicho[i]->makeSound();
		Cat* cat = dynamic_cast<Cat*>(bicho[i]); //wtf is dynamic cast
		if (cat)
			std::cout << "Cat idea is: "<< cat->getBrain().getIdea(i) << std::endl;
	
		Dog* dog = dynamic_cast<Dog*>(bicho[i]);
		if (dog)
		{
			dog->getBrain().setIdea(i, "Dogs food");
			std::cout << "Dog idea is: " << dog->getBrain().getIdea(i) << std::endl;
		}
	}
	for (int i = 0; i < max; i++)
		delete bicho[i];
}
