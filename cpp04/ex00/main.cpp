/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 23:04:48 by jeslin-tici       #+#    #+#             */
/*   Updated: 2026/01/17 12:10:32 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* i = new Dog();	
	const Animal* j = new Cat();
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
	delete(meta);
	delete (i);
	delete(j);
	delete(bruh1);
	delete(bruh2);
	
	return (0);
	
}