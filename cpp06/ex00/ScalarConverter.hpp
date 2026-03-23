/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:17:28 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/03/23 16:18:22 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <cmath>
# include <exception>
// std::stringstream ss(str);
// ss >> i -> string to int
// ss >> d -> string to double
// or convert it to c-tyle functions
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
		e_type getType(const std::string &input);

		class HandleEndgeCases : public std::exception
		{
			public:
				const char* what() const throw();
		};
	public:
		static void convert(const std::string &input);
};

#endif
