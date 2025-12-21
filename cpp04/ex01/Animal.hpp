/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:10:36 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/21 12:43:33 by jeslin-tici      ###   ########.fr       */
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
		~Animal();
		
		std::string getType(void) const;
		virtual void makeSound() const;
};

#endif