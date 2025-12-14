/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:32:53 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/13 16:37:43 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <iomanip>

class Fixed{
	private:
		int fixed_number;
		static const int bits = 8;
	
	public:
		Fixed();
		Fixed(const Fixed& newObj); // copy constructor
		Fixed& operator=(const Fixed& newObj); // copy assignment operator
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};
#endif