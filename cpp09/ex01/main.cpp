/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 14:23:15 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/10/09 13:41:19 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: not enough arguments" << std::endl;
        return (1);
    }
    try
    {
        RPN rpn(argv[1]);
        rpn.parseInput();
        rpn.calculate();
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}