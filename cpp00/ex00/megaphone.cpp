/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:57:39 by jeslin-tici       #+#    #+#             */
/*   Updated: 2026/04/13 16:49:32 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CXXtype>
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        int i = 1;
        while (i < argc)
        {
            std::string s = argv[i];
            for (size_t j = 0; j < s.size(); j++) 
                s[j] = std::toupper(s[j]);
            std::cout << s ;
            i++;
        }
        std::cout << std::endl;     //endl flushes the output, therefore affects performance, 
                                    // but I put it here because in my POV it looks more "CPP-ish"? At least for now
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    return (0);
}