/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:17:26 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/03/23 16:23:09 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& newObj)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = newObj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& newObj)
{
	std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	if (this != &newObj)
		*this = newObj;
	return (*this);
}

ScalarConverter::e_type ScalarConverter::getType(const std::string& input)
{
	try
	{
		if (input.length() == 1 && !isdigit(input[0]))
			return (CHAR);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
    try {
        size_t idx;
        std::stoi(input, &idx);
        if (idx == input.length())
            return (INT);
    }
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
    try {
        if (input.back() == 'f') {
            std::stof(input);
            return (FLOAT);
        }
    }
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
    try {
        std::stod(input);
        return (DOUBLE);
    }
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
    return (ERROR);
}

const char* ScalarConverter::HandleEndgeCases::what() const throw()
{
	return ("Error: Invalid input\n");
}


ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}
