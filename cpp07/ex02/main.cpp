/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:29:29 by vvazzs            #+#    #+#             */
/*   Updated: 2026/03/24 11:30:20 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
	Array<int> intArray(10);
	for (unsigned int i = 0; i < 10; ++i)
		intArray[i] = i * 10;
	for (unsigned int i = 0; i < intArray.size(); ++i)
		std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
	Array<std::string> strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "!";
	for (unsigned int i = 0; i < strArray.size(); ++i)
		std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;
	const Array<int> constIntArray = intArray;
	for (unsigned int i = 0; i < constIntArray.size(); ++i)
		std::cout << "constIntArray[" << i << "] = " << constIntArray[i] << std::endl;
    try {
        std::cout << intArray[10] << std::endl;
    } catch (std::exception & e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    try {
        std::cout << constIntArray[10] << std::endl;
    } catch (std::exception & e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
	return (0);
}