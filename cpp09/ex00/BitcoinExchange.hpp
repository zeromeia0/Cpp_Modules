/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 00:37:48 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/10/07 13:51:15 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE
 #define BITCOIN_EXCHANGE

 #include <iomanip>
 #include <iostream>
 #include <vector>
 #include <map>
 #include <list>
 #include <algorithm>
 #include <exception>
 #include <deque> 
 #include <exception>
#include <fstream>
#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _database;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        void loadDatabase(const std::string &file);
        float getRate(const std::string &date) const;
};

#endif