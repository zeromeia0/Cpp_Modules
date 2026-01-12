/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:57:04 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/23 00:25:41 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain brain;
	public:
		Dog();
		Dog(const Dog& newObj);
		Dog& operator=(const Dog& newObj);
		~Dog();

		void makeSound() const;
		Brain& getBrain();
		const Brain& getBrain() const;

};

#endif