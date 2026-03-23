/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:17:26 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/03/23 20:36:05 by vvazzs           ###   ########.fr       */
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
	if (this != &newObj){};
	return (*this);
}

ScalarConverter::e_type ScalarConverter::getType(const std::string& input)
{
	bool hasDot = false;
	bool hasF = false;
	size_t i = 0;

	if (input.empty())
		return (ERROR);
	if (input.length() == 1 && !isdigit(input[0]))
		return (CHAR);
	if (input == "nan" || input == "nanf" ||
		input == "+inf" || input == "+inff" ||
		input == "-inf" || input == "-inff")
		return (DOUBLE);
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (i >= input.length())
		return (ERROR);
	for (; i < input.length(); i++)
	{
		if (isdigit(input[i]))
			continue;
		else if (input[i] == '.' && !hasDot)
			hasDot = true;
		else if (input[i] == 'f' && i == input.length() - 1)
			hasF = true;
		else
			return (ERROR);
	}
	if (hasF && hasDot)
		return (FLOAT);
	if (hasDot)
		return (DOUBLE);
	if (!hasDot && !hasF)
		return (INT);
	return (ERROR);
}

const char* ScalarConverter::HandleEndgeCases::what() const throw()
{
	return ("Error: Invalid input\n");
}

int ScalarConverter::viniAtoi(const std::string& input)
{
	std::istringstream ss(input);
	int value;
	ss >> value;
	if (ss.fail() || !ss.eof())
		throw ScalarConverter::HandleEndgeCases();
	return (value);
}

float ScalarConverter::viniAtof(const std::string& input)
{
	std::istringstream ss(input);
	float value;
	ss >> value;
	if (ss.fail())
		throw ScalarConverter::HandleEndgeCases();
	return (value);
}

double ScalarConverter::viniAtod(const std::string& input)
{
	std::istringstream ss(input);
	double value;
	ss >> value;
	if (ss.fail())
		throw ScalarConverter::HandleEndgeCases();
	return (value);
}

bool ScalarConverter::handlePseudoLiterals(const std::string &input)
{
	if (input == "nan" || input == "nanf")
	{
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
		return (true);
	}
	if (input == "+inf" || input == "+inff")
	{
		std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n";
		return (true);
	}
	if (input == "-inf" || input == "-inff")
	{
		std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n";
		return (true);
	}
	return (false);
}


void ScalarConverter::printCharInt(double value)
{
	// CHAR
	if (value < 0 || value > 127 || isnan(value) || isinf(value))
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

	// INT
	if (isnan(value) || isinf(value))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloatDouble(double value)
{
	float f = static_cast<float>(value);

	// FLOAT
	if (f == static_cast<int>(f))
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;

	// DOUBLE
	if (value == static_cast<int>(value))
		std::cout << "double: " << value << ".0" << std::endl;
	else
		std::cout << "double: " << value << std::endl;
}
void ScalarConverter::convert(const std::string &input)
{
	try
	{
		if (handlePseudoLiterals(input))
			return;
		e_type type = getType(input);
		switch (type)
		{
			case CHAR:
			{
				char c = input[0];
				double value = static_cast<double>(c);
				if (!isprint(c))
					std::cout << "char: Non displayable" << std::endl;
				else
					std::cout << "char: '" << c << "'" << std::endl;
				std::cout << "int: " << static_cast<int>(c) << std::endl;
				printFloatDouble(value);
				break;
			}
			case INT:
			{
				int i = viniAtoi(input);
				double value = static_cast<double>(i);
				printCharInt(value);
				printFloatDouble(value);
				break;
			}
			case FLOAT:
			{
				std::string tmp = input.substr(0, input.length() - 1);
				float f = viniAtof(tmp);
				double value = static_cast<double>(f);
				printCharInt(value);
				printFloatDouble(value);
				break;
			}
			case DOUBLE:
			{
				double d = viniAtod(input);
				printCharInt(d);
				printFloatDouble(d);
				break;
			}
			default:
				throw HandleEndgeCases();
		}
	}
	catch (const HandleEndgeCases& e)
	{
		std::cout << e.what();
	}
	catch (const std::exception&)
	{
		std::cout << "Error: invalid input" << std::endl;
	}
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}


// vou deixar essa funcao aqui pq ficou mt foda
// void ScalarConverter::convert(const std::string &input)
// {
// 	try
// 	{
// 		e_type type = getType(input);

// 		switch (type)
// 		{
// 			case CHAR:
// 			{
// 				char c = input[0];
// 				std::cout << "char: '" << c << "'" << std::endl;
// 				std::cout << "int: " << static_cast<int>(c) << std::endl;
// 				std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
// 				std::cout << "double: " << static_cast<double>(c) << std::endl;
// 				break;
// 			}
// 			case INT:
// 			{
// 				int i = viniAtoi(input);
// 				if (i < 0 || i > 127)
// 					throw HandleEndgeCases();

// 				std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
// 				std::cout << "int: " << i << std::endl;
// 				std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
// 				std::cout << "double: " << static_cast<double>(i) << std::endl;
// 				break;
// 			}
// 			case FLOAT:
// 			{
// 				std::string tmp = input.substr(0, input.length() - 1); // tem que tirar o 'f' animal
// 				float f = viniAtof(tmp);
// 				std::cout << "char: " << static_cast<char>(f) << std::endl;
// 				std::cout << "int: " << static_cast<int>(f) << std::endl;
// 				std::cout << "float: " << f << "f" << std::endl;
// 				std::cout << "double: " << static_cast<double>(f) << std::endl;
// 				break;
// 			}
// 			case DOUBLE:
// 			{
// 				double d = viniAtod(input);
// 				std::cout << "double: " << d << std::endl;
// 				break;
// 			}
// 			default:
// 				throw HandleEndgeCases();
// 		}
// 	}
// 	catch (const HandleEndgeCases& e)
// 	{
// 		std::cout << e.what();
// 	}
// 	catch (const std::exception& e)
// 	{
// 		std::cout << "Standard exception: " << e.what() << std::endl;
// 	}
// }