/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 10:13:26 by vvazzs            #+#    #+#             */
/*   Updated: 2026/03/31 10:36:15 by vvazzs           ###   ########.fr       */
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
#include <deque> //container that allows fast insertion and removal at both ends

template <typename T>
typename T::iterator easyfind(T& container, int value)
            //must be iterator because it points to elements inside container regardless of data type and container
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found");
    return (it);
}

template <typename T>
typename T::const_iterator easyfind(const T& container, int value)
            //must be iterator because it points to elements inside container regardless of data type and container
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found");
    return (it);
}

#endif
