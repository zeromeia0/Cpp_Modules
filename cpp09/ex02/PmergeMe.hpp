
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 13:58:58 by vivaz-ca          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <cmath>
#include <stack>
# include <vector>
# include <map>
#include <sys/time.h>
# include <list>
# include <algorithm>
# include <exception>
# include <deque>
#include <climits>
#include <stdexcept>
# include <vector>
# include <deque>
# include <cstddef>

class PmergeMe
{
    private:
        struct _Item
        {
            int value;
            std::size_t id;
            _Item();
            _Item(int v, std::size_t i);
        };
        struct _Pair
        {
            _Item winner;
            _Item loser;
            _Pair(const _Item &w, const _Item &l);
        };
        bool lessItem(const _Item &a, const _Item &b);
        std::vector<std::size_t> jacobsthalOrder(std::size_t count);
        std::size_t findVectorPosition(const std::vector<_Item> &chain, int value, std::size_t end);
        std::size_t findDequePosition(const std::deque<_Item> &chain, int value, std::size_t end);
        void johnsonVector(std::vector<_Item> &items);
        void johnsonDeque(std::deque<_Item> &items);
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
        void parseInput(int argc, char *argv[], std::vector<int> &numbers);
        void sortVector(std::vector<int> &numbers);
        void sortDeque(std::deque<int> &numbers);
};

#endif
