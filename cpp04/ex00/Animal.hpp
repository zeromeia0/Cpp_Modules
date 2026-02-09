/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:10:36 by jeslin-tici       #+#    #+#             */
/*   Updated: 2026/02/09 09:54:56 by vvazzs           ###   ########.fr       */
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
		
		virtual void makeSound() const;
		std::string getType(void) const;
};

#endif