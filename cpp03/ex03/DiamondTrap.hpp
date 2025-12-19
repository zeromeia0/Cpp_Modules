/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:00:02 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/19 21:44:28 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(std::string newName);
		DiamondTrap(const DiamondTrap& newObj);
		DiamondTrap& operator=(const DiamondTrap& newObj);
		~DiamondTrap();

		void whoAmI(void);
		void attack(const std::string& target);

};

#endif
