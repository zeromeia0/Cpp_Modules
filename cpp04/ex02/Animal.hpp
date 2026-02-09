/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:10:36 by jeslin-tici       #+#    #+#             */
/*   Updated: 2026/02/09 10:03:36 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <iomanip>
# include <cmath>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal& newObj);
		Animal& operator=(const Animal& newObj);
		virtual ~Animal();
		
		std::string getType(void) const;
		virtual void makeSound() const = 0; //object must be 100% complete to exist
		
};

#endif