/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 04:14:55 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/21 04:18:52 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
#include "WrongAnimal.hpp"
# include <iostream>
# include <iomanip>
# include <cmath>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& newObj);
		WrongCat& operator=(const WrongCat& newObj);
		~WrongCat();

		void makeSound();
		std::string getType(void);
};

#endif
