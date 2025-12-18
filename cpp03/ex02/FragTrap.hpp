/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:33:55 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/18 20:36:48 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string newName);
		FragTrap(const FragTrap& newObj);
		FragTrap& operator=(const FragTrap& newOb);
		~FragTrap();
		
		void attack(const std::string& target);
		void printInfo();
		void highFivesGuys(void);
};
#endif