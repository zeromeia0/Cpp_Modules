/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:57:04 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/22 23:26:10 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain brain;
	public:
		Cat();
		Cat(const Cat& newObj);
		Cat& operator=(const Cat& newObj);
		~Cat();

		void makeSound() const;
		const Brain& getBrain() const;
};

#endif