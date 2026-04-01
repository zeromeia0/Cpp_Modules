/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:04:48 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/04/01 01:43:29 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>

#include <iostream>
#include "Span.hpp"

void printSection(const std::string& title)
{
    int width = 50;
    int padding = (width - title.size()) / 2;

    std::cout << "\n" << std::string(width, '=')
              << "\n" << std::string(padding, ' ') << title
              << std::string(padding, ' ') << "\n"
              << std::string(width, '=') << "\n";
}

void runTest(const std::string& title, void (*testFunc)())
{
    printSection(title);
    try
    {
        testFunc();
        std::cout << "✅ Test passed\n";
    }
    catch (const std::exception& e)
    {
        std::cout << "❌ Error: (" << e.what() << ")\n";
    }
}

void testDefault()
{
    Span test1;
    test1.addNumber(3); //shouldn't work
}

void testBasic()
{
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest : " << sp.longestSpan() << std::endl;
    sp.addNumber(1); //Throw
}

void testLarge()
{
    int ammount = 1000;
    Span big(ammount);
    std::vector<int> v;
    for (int i = 0; i < ammount; i++)
        v.push_back(rand()); //study this
    big.addInRange(v.begin(), v.end());
    std::cout << "Shortest: " << big.shortestSpan() << std::endl;
    std::cout << "Longest : " << big.longestSpan() << std::endl;
}

int main()
{
    runTest("Testing Default Constructor", testDefault);
    runTest("Testing Basic Functionality", testBasic);
    runTest("Testing Large Dataset", testLarge);
    return (0);
}