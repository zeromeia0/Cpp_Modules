/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:17:28 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/03/24 09:53:04 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <cmath>
# include <exception>
# include <sstream>
# include <cmath>
#include <math.h>
// std::stringstream ss(str);
// ss >> i -> string to int
// ss >> d -> string to double
// or convert it to c-tyle ftions
// std::atoi and atof
// char* end;
// 
// int i = std::strtol(str.c_str(), &end, 10);
// double d = std::strtod(str.c_str(), &end);
class ScalarConverter
{
	private:
		enum e_type
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			ERROR
		};
		ScalarConverter();
		ScalarConverter(const ScalarConverter& newObj);
		ScalarConverter& operator=(const ScalarConverter& newObj);
		~ScalarConverter();
		static e_type getType(const std::string &input);
		static int viniAtoi(const std::string& input);
		static float viniAtof(const std::string& input);
		static double viniAtod(const std::string& input);
		static void printCharInt(double value);
		static void printFloatDouble(double value);
		static bool handlePseudoLiterals(const std::string &input);
		class HandleEndgeCases : public std::exception
		{
			public:
				const char* what() const throw();
		};
	public:
		static void convert(const std::string &input);
};

#endif
