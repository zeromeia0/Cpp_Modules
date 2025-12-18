/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:28:11 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/18 20:21:34 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <iomanip>
# include <cmath>
# define maxHP 100

class ClapTrap
{
	protected:
		std::string name;
		int healthPoints;
		int energyPoints;
		int attackDamage;	
	
	public:
		ClapTrap();
		ClapTrap(std::string name, int hp, int energy, int damage);
		ClapTrap(std::string newName);
		ClapTrap(const ClapTrap& newObj);
		ClapTrap& operator=(const ClapTrap& newObj);
		~ClapTrap();
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
#endif