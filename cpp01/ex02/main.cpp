/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:50:17 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/01/12 13:20:40 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;
	std::string &stringREF = str;
	std::cout << "\n";
	std::cout << "Address of str: " << &str << std::endl;
	std::cout << "Address of stringPTR: " << stringPTR << std::endl;
	std::cout << "Address of stringREF: " << &stringREF << std::endl;
	std::cout << "\n";
	std::cout << "Value of str = " << str << std::endl;
	std::cout << "Value pointed to by stringPTR = " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF = " << stringREF << std::endl;
	return (0);
}