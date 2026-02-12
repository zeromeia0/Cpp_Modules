/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 00:01:14 by jeslin-tici       #+#    #+#             */
/*   Updated: 2026/01/15 12:25:33 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
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