/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:34:05 by vvazzs            #+#    #+#             */
/*   Updated: 2026/01/12 13:05:55 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cctype>

int    StrIsDigit(std::string s)
{
    int i = 0;
    if (s.empty())
        return (1);
    while (s[i])
    {
        if (!std::isdigit(s[i]))
            return (0);
        i++;
    }
    return (1);
}

std::string InputValidation(const std::string &prompt)
{
    std::string input;

    while (1)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input)) //comeback here at home just check stuff
        {
            if (std::cin.eof())
                return "";
        }
        if (input.empty())
            std::cout << "Can't have empty information :D\n";
        else
            break ;
    }
    return (input);
}

int Contact::SetInfo(void)
{
    
    FirstName = InputValidation("Insert first name: ");
    if (FirstName.empty())
        return (0);

    LastName = InputValidation("Insert last name: ");
    if (LastName.empty())
        return (0);

    Nickname = InputValidation("Insert nickname: ");
    if (Nickname.empty())
        return (0);

    while (1)
    {
        PhoneNumber = InputValidation("Insert phone number: ");

        if (PhoneNumber.empty())
            return (0);
        if (StrIsDigit(PhoneNumber) == 0)
        {
            std::cout << "Only digits allowed\n";
            continue;
        }
        else if (PhoneNumber.size() < 7 || PhoneNumber.size() > 12)
        {
            std::cout << "Phone number must be between 7 and 12 digits :D\n";
            continue;
        }
        else
            break;
    }
    if (PhoneNumber.empty()) return (0);
    DarkestSecret = InputValidation("Insert darkest secret: ");
    if (DarkestSecret.empty()) return (0);
    return (1);
}

std::string Contact::FormatBook(std::string s) const
{
    if (s.length() > 10)
        return s.substr(0, 9) + "."; //study this again
    return (s);
}

void Contact::DisplayGeneralContacts(int index) const
{
    std::cout << "|" 
              << std::setw(10) << index << "|"
              << std::setw(10) << FormatBook(FirstName) << "|"
              << std::setw(10) << FormatBook(LastName) << "|"
              << std::setw(10) << FormatBook(Nickname) << "|\n";
}

void Contact::DisplayFullInformation()
{
    std::cout << "First name: " << FirstName << std::endl;
    std::cout << "Last name: " << LastName << std::endl;
    std::cout << "Nickname: " << Nickname << std::endl;
    std::cout << "Phone number: " << PhoneNumber << std::endl;
    std::cout << "Darkest secret: " << DarkestSecret << std::endl;
}
