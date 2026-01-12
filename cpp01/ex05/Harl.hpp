/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 00:01:14 by jeslin-tici       #+#    #+#             */
/*   Updated: 2026/01/12 13:39:06 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARD_HPP
#include <iostream>
#include <iomanip>

class Harl{
	private:
		std::string name;
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		Harl() {};
		Harl(std::string newName) : name(newName) { std::cout << "Creating harl: " << newName << std::endl;}; //why not calling it?
		Harl(const char *check_name);
		~Harl() {};
		void complain(std::string level);
		void complain(const char *level);
};

#endif