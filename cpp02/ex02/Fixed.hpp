/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 09:38:58 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/16 18:06:56 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <iomanip>
# include <cmath>

class Fixed{
	private:
		int fixed_number;
		static const int bits = 8;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& newObj);
		Fixed& operator=(const Fixed& newObj);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;
		
		bool operator>(const Fixed& target) const;
		bool operator<(const Fixed& target) const;	
		bool operator>=(const Fixed& target) const;
		bool operator<=(const Fixed& target) const;
		bool operator==(const Fixed& target) const;
		bool operator!=(const Fixed& target) const;

		Fixed operator+(const Fixed& target) const;
		Fixed operator-(const Fixed& target) const;
		Fixed operator*(const Fixed& target) const;
		Fixed operator/(const Fixed& target) const;

		Fixed& operator++();
		Fixed operator++(int n);
		Fixed& operator--();
		Fixed operator--(int n);
};

std::ostream& operator<<(std::ostream& out, const Fixed& value);





#endif