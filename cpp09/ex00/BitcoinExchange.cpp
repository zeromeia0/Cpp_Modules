/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 00:37:19 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/10/07 13:56:37 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>
#include <string>

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::loadDatabase(const std::string &file)
{
    std::ifstream file_s(file.c_str());
    if (!file_s)
        throw (std::runtime_error("Error: can't open database"));
    std::string line;
    std::getline(file_s, line); //_database["2011-01-07] = 32
}

float BitcoinExchange::getRate(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it;
    it  = _database.lower_bound(date); //study
    if (it != _database.end() && it->first == date)
        return it->second;
    if (it == _database.begin())
        throw (std::runtime_error("Error: date is before DB range"));
    --it;
    return it->second;
}