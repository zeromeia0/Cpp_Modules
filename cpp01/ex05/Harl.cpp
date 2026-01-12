/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 00:01:11 by jeslin-tici       #+#    #+#             */
/*   Updated: 2026/01/12 13:38:08 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(const char *check_name)
{
	if (check_name == NULL)
		name = "UnnamedHarl";
	else
		name = std::string(check_name);	
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	if (level.empty())
		return ;
	void (Harl::*ptr[])(void) = //dont forget to comeback here and study + review
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	
	std::string input[] = {
		"DEBBUG", "INFO", "WARNING", "ERROR"
	};
	for (long unsigned int i = 0; i < sizeof(input) / sizeof(std::string); i++)
	{
		if (input[i] == level)
		{
			std::cout << name << " is complaining: ";
			(this->*ptr[i])();
			std::cout << "\n";
		}
	}	
}

void Harl::complain(const char* level)
{
    if (level == NULL) {
        std::cout << "Invalid complain\n";
        return;
    }
    complain(std::string(level));
}
