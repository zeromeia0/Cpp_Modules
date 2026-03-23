/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 20:07:49 by vvazzs            #+#    #+#             */
/*   Updated: 2026/03/23 20:38:33 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void runAllTests()
{
	struct TestGroup
	{
		const std::string* tests;
		int size;
		const std::string title;
	};
	static const std::string charTests[] = {
		"a", "Z", "\n", " "
	};
	static const std::string intTests[] = {
		"42", "+42", "-42", "0",
		"2147483647", "-2147483648"
	};
	static const std::string floatTests[] = {
		"42.0f", "-42.42f", "+42.42f", "0.0f", "123f"
	};
	static const std::string doubleTests[] = {
		"42.0", "-42.42", "+42.42", "0.0"
	};
	static const std::string pseudoTests[] = {
		"nan", "nanf",
		"+inf", "-inf",
		"+inff", "-inff"
	};
	static const std::string invalidTests[] = {
		"", "abc", "42abc",
		"++42", "--42", "+-42", "-+42",
		"4.2.2", "42f.0", "f42", "42.0ff"
	};
	static const std::string edgeTests[] = {
		"127", "128", "31",
		"999999999999", "-999999999999"
	};
	TestGroup groups[] = {
		{charTests, sizeof(charTests)/sizeof(std::string), "CHAR TESTS"},
		{intTests, sizeof(intTests)/sizeof(std::string), "INT TESTS"},
		{floatTests, sizeof(floatTests)/sizeof(std::string), "FLOAT TESTS"},
		{doubleTests, sizeof(doubleTests)/sizeof(std::string), "DOUBLE TESTS"},
		{pseudoTests, sizeof(pseudoTests)/sizeof(std::string), "PSEUDO LITERALS"},
		{invalidTests, sizeof(invalidTests)/sizeof(std::string), "INVALID INPUTS"},
		{edgeTests, sizeof(edgeTests)/sizeof(std::string), "EDGE CASES"}
	};
	int groupCount = sizeof(groups) / sizeof(TestGroup);
	for (int g = 0; g < groupCount; g++)
	{
		std::cout << "\n===== " << groups[g].title << " =====" << std::endl;

		for (int i = 0; i < groups[g].size; i++)
		{
			std::cout << "\nInput: [" << groups[g].tests[i] << "]" << std::endl;
			ScalarConverter::convert(groups[g].tests[i]);
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert <literal>" << std::endl;
		return (1);
	}
    // std::cout << "Trying to instatiate ScalarCOnverter" << std::endl;
    // ScalarConverter testing;
	ScalarConverter::convert(argv[1]);
	return (0);
}