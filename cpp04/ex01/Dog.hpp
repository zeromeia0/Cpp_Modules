/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:57:04 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/22 20:23:11 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal, public Brain
{
	public:
		Dog();
		Dog(const Dog& newObj);
		Dog& operator=(const Dog& newObj);
		~Dog();

		void makeSound();
};

#endif