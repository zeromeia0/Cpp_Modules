/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 20:07:49 by vvazzs            #+#    #+#             */
/*   Updated: 2026/04/15 18:43:07 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Usage: ./convert <literal>" << std::endl;
		return (1);
	}
    // std::cout << "Trying to instatiate ScalarCOnverter" << std::endl;
    // ScalarConverter testing;
	ScalarConverter::convert(argv[1]);
	return (0);
}