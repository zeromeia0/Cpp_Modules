/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 09:48:42 by vvazzs            #+#    #+#             */
/*   Updated: 2026/03/24 09:48:43 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
template <typename T>
T& min(T &a, T &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
template <typename T>
T& max(T &a, T &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif