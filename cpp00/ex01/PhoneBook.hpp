/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:23:01 by vvazzs            #+#    #+#             */
/*   Updated: 2026/01/12 13:09:43 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cstdio>
#include <cctype>
#include "Contact.hpp"

class PhoneBook
{
    private:
        int count;
    public:
        Contact _contacts[8];
        PhoneBook() : count(0) {}; // study again
        
        int AddContact()
        {
            int index = count % 8;
            if (_contacts[index].SetInfo() == 0)
                return (0);
            count++;
            return (1);
        }
        
        void DisplayAllContacts() const
        {
            int n = count < 8 ? count : 8;
            std::cout << "\n*===============| CONTACTS |================*\n";
            std::cout << "|" << std::setw(10) << "Index"
                      << "|" << std::setw(10) << "FirstName"
                      << "|" << std::setw(10) << "LastName"
                      << "|" << std::setw(10) << "Nickname"
                      << "|\n";
            std::cout << "*-------------------------------------------*\n";
            for (int i = 0; i < n; i++)
                _contacts[i].DisplayGeneralContacts(i);
            std::cout << "*===========================================*\n\n";
        }
        
        int DeepSearch()
        {
            int index;
            std::string input;            
            while (1)
            {
                if (count == 0)
                    return (std::cout << "Poor you! You have no friends to contact :'( \
                        \nADD them and then comeback here :D\n", 1);
                std::cout << "What person[index] are you looking for?: ";
                std::getline(std::cin, input);
                if (std::cin.eof())
                    return (0);
                if (input.empty())
                    std::cout << "Can't be empty\n";
                else
                    break ;
            }
            if (!StrIsDigit(input))
                return (std::cout << "This is an invalid index \n", -1);
            index = atoi(input.c_str());
            if (index < 0 || index >= 8)
                return (std::cout << "This is an invalid index\n", -1);
            else if (index >= count)
                return (std::cout << "There is still no contact with this index dear user :D\n", -1);
            else
                _contacts[index].DisplayFullInformation();
        return (1);
    }
};
// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); <-- LEAVING THIS HERE TO STUDY LATER IF I WANT TO

#endif
