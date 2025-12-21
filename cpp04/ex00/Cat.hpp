/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:57:04 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/21 04:21:46 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& newObj);
		Cat& operator=(const Cat& newObj);
		~Cat();

		void makeSound();
};

#endif