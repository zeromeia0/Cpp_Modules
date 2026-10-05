/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 10:13:26 by vvazzs            #+#    #+#             */
/*   Updated: 2026/06/02 05:19:35 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <exception>
#include <deque> 
    //container that allows fast insertion and removal at both ends
    // mix between dynamic array (vector) and a queue
    //const_iterator is a type defined by container
template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found");
    return (it);
}

template <typename T>
typename T::const_iterator easyfind(const T& container, int value)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found");
    return (it);
}

template <typename T>
void print_container(const T& container)
{
	for (typename T::const_iterator n = container.begin(); n != container.end(); ++n)
		std::cout << "[" << *n << "]" << ' ';
	std::cout << '\n';
}

template <typename T>
void find_it(const T& container, int value)
{
    try 
    {
		if (container.empty())
			throw (std::runtime_error("Empty container"));
        if (easyfind(container, value) != container.end())
            std::cout << "Value " << value << " found.\n";
    }
    catch (const std::exception& e)
    {
        std::cout << "Value " << value << " not found (Exception: " << e.what() << ")\n";
    }
}

#endif
