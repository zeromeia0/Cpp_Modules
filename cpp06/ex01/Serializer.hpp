/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 20:38:44 by vvazzs            #+#    #+#             */
/*   Updated: 2026/03/24 09:22:44 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <iomanip>
# include <cmath>
#include <stdint.h>

struct Data
{
	int intValue;
	double dblValue;
	std::string strValue;	
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer&);
		Serializer& operator=(const Serializer&);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
