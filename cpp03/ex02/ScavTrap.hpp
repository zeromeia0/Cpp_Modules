/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:15:34 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/18 20:07:58 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string newName);
		ScavTrap(const ScavTrap& newObj);
		ScavTrap& operator=(const ScavTrap& newOb);
		~ScavTrap();
		
		void attack(const std::string& target);
		void guardGate();
		void printInfo();
};

#endif