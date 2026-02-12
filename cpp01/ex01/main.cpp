/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:56:43 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/11/25 22:51:24 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int    StrIsDigit(std::string s)
{
    int i = 0;
    if (s.empty())
        return (1);
    while (s[i])
    {
        if (!std::isdigit(s[i]))
            return (0);
        i++;
    }
    return (1);
}

int hordeChecker(std::string &input) // EU SOU FUCKING IMPARAVEL
{
	while (1)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (std::cout << "Aborting mission\n", 0);
		if (input.empty())
			std::cout << "I asked you a question!: ";
		else if (!StrIsDigit(input))
			std::cout << "I need to know in numbers, god damn it!: ";
		else
			break ;
	}
	return (1);
}

int main(void)
{
	int n;
	std::string input;
	std::string hordeName;
	
	std::cout << "Attention everyone! We have spoted a horde of: ";
	if (hordeChecker(input) == 0)
		return (1);

	n = atoi(input.c_str());	
	
	std::cout << "All right you weirdo, what do you call them this time?: ";
	
	while (1)
	{
		if (!std::getline(std::cin, hordeName))
		{
			if (std::cin.eof())
				return (std::cout << "Aborting mission\n", 1);
		}
		if (hordeName.empty())
			std::cout << "We need a name for the report later!: ";
		else
			break;
	}
	Zombie *horde = zombieHorde(n, hordeName);
	if (!horde)
		return (std::cout << "Aborting mission\n", 1);
	delete[] horde;
	std::cout << "==Horde annihilated, mission completed==\n";
	return (0);
}
