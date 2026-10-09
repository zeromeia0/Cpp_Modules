/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 22:20:34 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/10/09 22:22:42 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <stdexcept>
#include <string>
#include <climits>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other){(void)other;}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other;
    return *this;
}

PmergeMe::_Item::_Item() : value(0), id(0) {}
PmergeMe::_Item::_Item(int v, std::size_t i) : value(v), id(i) {}
PmergeMe::_Pair::_Pair(const _Item &w, const _Item &l) : winner(w), loser(l) {}
bool PmergeMe::lessItem(const _Item &a, const _Item &b)
{
    return (a.value < b.value);
}

void PmergeMe::parseInput(int argc, char **argv, std::vector<int> &numbers)
{
    if (argc < 2)
        throw (std::runtime_error("Error: missing input"));
    for (int i = 1; i < argc; ++i)
    {
        const std::string token(argv[i]);
        if (token.empty())
            throw std::runtime_error("Error: empty argument");
        int value = 0;
        for (std::size_t j = 0; j < token.size(); ++j)
        {
            if (token[j] < '0' || token[j] > '9')
                throw std::runtime_error("Error: invalid positive integer");
            const int digit = token[j] - '0';
            if (value > (INT_MAX - digit) / 10)
                throw std::runtime_error("Error: integer overflow");
            value = value * 10 + digit;
        }
        if (value == 0)
            throw std::runtime_error("Error: zero is not positive");
        numbers.push_back(value);
    }
}

std::vector<std::size_t> PmergeMe::jacobsthalOrder(std::size_t count)
{
    std::vector<std::size_t> result;
    if (count == 0)
        return (result);
    result.push_back(1);
    std::size_t previous = 1;
    std::size_t current = 3;
    while (previous < count)
    {
        const std::size_t end = current < count ? current : count;
        for (std::size_t i = end; i > previous; --i)
            result.push_back(i);
        if (end == count)
            break;
        if (previous >(static_cast<std::size_t>(-1) - current) / 2)
        {
            previous = current;
            current = count;
        }
        else
        {
            const std::size_t next = current + 2 * previous;
            previous = current;
            current = next;
        }
    }
    return (result);
}

std::size_t PmergeMe::findVectorPosition(const std::vector<_Item> &chain,int value,std::size_t end)
{
    std::size_t left = 0;
    std::size_t right = end;
    while (left < right)
    {
        const std::size_t mid = left + (right - left) / 2;
        if (chain[mid].value < value)
            left = mid + 1;
        else
            right = mid;
    }
    return (left);
}

std::size_t PmergeMe::findDequePosition(const std::deque<_Item> &chain,int value,std::size_t end)
{
    std::size_t left = 0;
    std::size_t right = end;
    while (left < right)
    {
        const std::size_t mid =left + (right - left) / 2;
        if (chain[mid].value < value)
            left = mid + 1;
        else
            right = mid;
    }
    return (left);
}

void PmergeMe::johnsonVector(std::vector<_Item> &items)
{
    if (items.size() < 2)
        return;
    std::vector<_Pair> pairs;
    std::vector<_Item> winners;
    for (std::size_t i = 0; i + 1 < items.size(); i += 2)
    {
        if (lessItem(items[i], items[i + 1]))
            pairs.push_back(_Pair(items[i + 1], items[i]));
        else
            pairs.push_back(_Pair(items[i], items[i + 1]));
        winners.push_back(pairs.back().winner);
    }
    const bool hasOdd = items.size() % 2 != 0;
    const _Item odd = hasOdd ? items.back() : _Item();
    johnsonVector(winners);
    std::vector<_Item> chain;
    for (std::size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].winner.id == winners[0].id)
        {
            chain.push_back(pairs[i].loser);
            break;
        }
    }
    chain.insert(chain.end(), winners.begin(), winners.end());
    const std::size_t count =winners.size() + (hasOdd ? 1 : 0);
    const std::vector<std::size_t> order =jacobsthalOrder(count);
    for (std::size_t k = 1; k < order.size(); ++k)
    {
        const std::size_t index = order[k];
        _Item pending;
        std::size_t bound = chain.size();
        if (hasOdd && index == winners.size() + 1)
            pending = odd;
        else
        {
            const _Item partner = winners[index - 1];
            for (std::size_t i = 0; i < pairs.size(); ++i)
            {
                if (pairs[i].winner.id == partner.id)
                {
                    pending = pairs[i].loser;
                    break;
                }
            }
            for (std::size_t i = 0; i < chain.size(); ++i)
            {
                if (chain[i].id == partner.id)
                {
                    bound = i;
                    break;
                }
            }
        }
        const std::size_t position = findVectorPosition(chain, pending.value, bound);
        chain.insert(chain.begin() + position, pending);
    }
    items.swap(chain);
}

void PmergeMe::johnsonDeque(std::deque<_Item> &items)
{
    if (items.size() < 2)
        return;
    std::deque<_Pair> pairs;
    std::deque<_Item> winners;
    for (std::size_t i = 0;i + 1 < items.size(); i += 2)
    {
        if (lessItem(items[i], items[i + 1]))
            pairs.push_back(_Pair(items[i + 1], items[i]));
        else
            pairs.push_back(_Pair(items[i], items[i + 1]));
        winners.push_back(pairs.back().winner);
    }
    const bool hasOdd = items.size() % 2 != 0;
    const _Item odd = hasOdd ? items.back() : _Item();
    johnsonDeque(winners);
    std::deque<_Item> chain;
    for (std::size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].winner.id == winners[0].id)
        {
            chain.push_back(pairs[i].loser);
            break;
        }
    }
    chain.insert(chain.end(), winners.begin(), winners.end());
    const std::size_t count =
        winners.size() + (hasOdd ? 1 : 0);
    const std::vector<std::size_t> order =
        jacobsthalOrder(count);
    for (std::size_t k = 1; k < order.size(); ++k)
    {
        const std::size_t index = order[k];
        _Item pending;
        std::size_t bound = chain.size();
        if (hasOdd && index == winners.size() + 1)
            pending = odd;
        else
        {
            const _Item partner = winners[index - 1];
            for (std::size_t i = 0; i < pairs.size(); ++i)
            {
                if (pairs[i].winner.id == partner.id)
                {
                    pending = pairs[i].loser;
                    break;
                }
            }
            for (std::size_t i = 0; i < chain.size(); ++i)
            {
                if (chain[i].id == partner.id)
                {
                    bound = i;
                    break;
                }
            }
        }
        const std::size_t position =findDequePosition(chain, pending.value, bound);
        chain.insert(chain.begin() + position, pending);
    }
    items.swap(chain);
}

void PmergeMe::sortVector(std::vector<int> &numbers)
{
    std::vector<_Item> items;
    items.reserve(numbers.size());
    for (std::size_t i = 0; i < numbers.size(); ++i)
        items.push_back(_Item(numbers[i], i));
    johnsonVector(items);
    for (std::size_t i = 0; i < numbers.size(); ++i)numbers[i] = items[i].value;
}

void PmergeMe::sortDeque(std::deque<int> &numbers)
{
    std::deque<_Item> items;
    for (std::size_t i = 0; i < numbers.size(); ++i)
        items.push_back(_Item(numbers[i], i));
    johnsonDeque(items);
    for (std::size_t i = 0; i < numbers.size(); ++i)numbers[i] = items[i].value;
}

PmergeMe::~PmergeMe() {}
