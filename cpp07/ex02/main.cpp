/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:29:29 by vvazzs            #+#    #+#             */
/*   Updated: 2026/05/02 09:22:27 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <string>
#include "Array.hpp"

void subject(void)
{
	try
	{
		std::cout << "====Tring the subject shit====" << std::endl;
		int* a = new int();
		std::cout << *a << std::endl;
		delete(a);
	}
	catch(std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "====Finished testing subject shit====" << std::endl;	
}
int main()
{
	subject();

	std::cout << "==== Testing with int array ====\n";
	Array<int> intArray(10);
	for (unsigned int i = 0; i < intArray.size(); ++i)
		intArray[i] = i * 10;
	for (unsigned int i = 0; i < intArray.size(); ++i)
		std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    try
	{
        std::cout << intArray[10] << std::endl;
    } catch (std::exception & e)
	{
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }


	std::cout << "==== Testing with string array ====\n";
	Array<std::string> strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "!";
	for (unsigned int i = 0; i < strArray.size(); ++i)
		std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;

	std::cout << "==== Testing with const int array ====\n";
	const Array<int> constIntArray = intArray;
	for (unsigned int i = 0; i < constIntArray.size(); ++i)
		std::cout << "constIntArray[" << i << "] = " << constIntArray[i] << std::endl;
    try
	{
        std::cout << constIntArray[10] << std::endl;
    }
	catch (std::exception & e)
	{
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }


	std::cout << "==== Testing with unsigned int array ====\n";
	Array<unsigned int> UnIntArray(5);
	for (unsigned int i = 0; i < UnIntArray.size(); i++)
		UnIntArray[i] = i + 1;
	for (unsigned int i = 0; i < UnIntArray.size(); i++)
		std::cout << "UnIntArray [" << UnIntArray[i] << "]" << std::endl;

	try
	{
		std::cout << "==== Testing with out of size shit ====\n";
		Array<bool> sizeless(3);
		for (unsigned int i = 0; i < 5; i++)
			sizeless[i] = "true";
		for (unsigned int i = 0; i < 5; i++)
			std::cout << "Array = " << sizeless[i] << std::endl;	
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "==== Testing with under bounds shit ====\n";
		Array<int> under(4);
		for(unsigned int i = 0; i < 2; i++)
			under[i] = i + (7*3);
		for (unsigned int i = 0; i < under.size(); i++)
			std::cout << "Array = " << under[i] << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}