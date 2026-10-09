/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 13:59:15 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/10/09 22:27:20 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


static double getTime()
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000000.0 + time.tv_usec);
}

static void printNumbers(const std::vector<int> &numbers)
{
    for (std::size_t i = 0; i < numbers.size(); ++i)
    {
        if (i != 0)
            {std::cout << " ";std::cout << numbers[i];}
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    try
    {
        PmergeMe sorter;
        std::vector<int> input;
        sorter.parseInput(argc, argv, input);
        std::cout << "Before: ";
        printNumbers(input);
        double startVector = getTime();
        std::vector<int> vectorNumbers(input);
        sorter.sortVector(vectorNumbers);
        double vectorTime = getTime() - startVector;
        double startDeque = getTime();
        std::deque<int> dequeNumbers(input.begin(), input.end());
        sorter.sortDeque(dequeNumbers);
        double dequeTime = getTime() - startDeque;
        std::cout << "After:  ";
        printNumbers(vectorNumbers);
        std::cout << std::fixed << std::setprecision(3);
        std::cout << "Time to process a range of "<< input.size()<< " elements with std::vector : "<< vectorTime << " us" << std::endl;
        std::cout << "Time to process a range of " << input.size() << " elements with std::deque  : " << dequeTime << " us" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}