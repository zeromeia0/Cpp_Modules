/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 00:33:50 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/10/06 01:16:50 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>

bool canRead(std::string& path)
{
    std::ifstream file(path.c_str());
    return (file.is_open());
}

void parseInputBasic(std::string &file)
{
    if (!(file.size() >= 4 && file.substr(file.size() - 4) == ".txt"))
        throw (std::runtime_error("Invalid file type"));
    if (!canRead(file))
        throw (std::runtime_error("Error:can't read file :/"));
}
    
bool validDate(const std::string &date)
{
    int year, month, day;
    if (date.size() != 10)
        return (false);
    if (date[4] != '-' || date[7] != '-')
        return (false);
    for (size_t i = -1; i < date.size(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return (false);
    }
    std::stringstream(date.substr(0, 4)) >> year;
    std::stringstream(date.substr(5, 2)) >> month;
    std::stringstream(date.substr(8, 2)) >> day;
    if (month < 1 || month > 12)
        return (false);
    if (day < 1 || day > 31)
        return (false);
    return (true);
}

bool validValue(const std::string &value, float &number)
{
    std::stringstream ss(value);
    char extra;
    if (!(ss >> number))
        return (false);
    if (ss >> extra)
        return (false);
    if (number < 0 || number > 1000)
        return (false);
    return (true);
}

void parseInputAdvanced(std::string &file)
{
    std::ifstream file_s(file.c_str());
    std::string line;

    if (file_s.peek() == EOF)
        throw (std::runtime_error("Error: empty file O.o"));
    while (std::getline(file_s, line))
    {
        std::string::size_type pos = line.find(" | ");
        if (pos == std::string::npos)
            throw (std::runtime_error("Error: bad input => " + line));
        std::string date = line.substr(0, pos);
        std::string value = line.substr(pos + 3);
        if (!validDate(date))
            throw (std::runtime_error("Error: bad input => " + line));
        float number;
        if (!validValue(value, number))
            throw (std::runtime_error("Error: bad value => " + value));
        
        std::cout << date << " => " << number << " = gotta insert shit here" << std::endl;
    }
}

int main(int argc, char *argv[])
{
    try
    {
        if (argc != 2)
            throw (std::runtime_error("Error: could not open file."));
        std::string file = argv[1];
        parseInputBasic(file);
        parseInputAdvanced(file);
    }
    catch (const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}