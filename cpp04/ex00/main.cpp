/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 23:04:48 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/21 04:23:15 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	Animal* meta = new Animal();
	Animal* i = new Dog();	
	Animal* j = new Cat();
	WrongAnimal *bruh1 = new WrongAnimal();
	WrongAnimal *bruh2 = new WrongCat();

	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << bruh1->getType() << " " << std::endl;
	std::cout << bruh2->getType() << " " << std::endl;
	bruh1->makeSound();
	bruh2->makeSound();
	return (0);
	
}