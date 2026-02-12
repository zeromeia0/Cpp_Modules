/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 22:26:32 by jeslin-tici       #+#    #+#             */
/*   Updated: 2026/01/15 12:19:52 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "notLosers.hpp"

std::string replace_strings(std::string line, std::string s1, std::string s2)
{
	size_t index = 0;
	while ((index = line.find(s1, index)) != std::string::npos) 
					//result of the line.find() is assignged to index
					//find() -> searches for substring inside a string
					// and tells where it starts
					// index != npos -> substring was found
					// npos = no position (search failed)
					
	{
		line.erase(index, s1.length());
		line.insert(index, s2);
		index += s2.length();
	}
	return (line);
}

int main(int argc, char *argv[])
{
	if (argc != 4 || argv[1][0] == '\0' || argv[2][0] == '\0' || argv[3][0] == '\0')
		return (1);

	std::ifstream originalFile(argv[1]);
	if (!originalFile)
		return (std::cout << "Error: [" << argv[1] << "]: File not found\n", 1);

	std::string replacedName = std::string(argv[1]) + ".replace";
	std::ofstream replacedFile(replacedName.c_str());
	std::string line;

	while (std::getline(originalFile, line))
	{
		std::string final_str = replace_strings(line, argv[2], argv[3]);
		replacedFile << final_str << "\n";
	}		
	return (0);
}

// ifstream -> pipe from file to program (read)
// ofstream -> pipe from program to file (write)
// std::ifstream f("file.txt");

// f.is_open();     true if file opened
// f.good();        stream is OK
// f.fail();        last operation failed
// f.eof();         reached end of file