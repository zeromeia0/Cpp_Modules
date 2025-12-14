/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:29:04 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/13 16:58:27 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a; // default const
	Fixed b(a); // copy constructor in this case
	Fixed c;
	c = b; //assignment
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << "----------------------------\n";
	Fixed d(a);
	std::cout << "Before: " << d.getRawBits() << std::endl;
	d.setRawBits(5);
	std::cout << "After: " << d.getRawBits() << std::endl;
	return (0);
}