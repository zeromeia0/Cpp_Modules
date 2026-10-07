/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 14:21:46 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/10/07 14:21:47 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <iomanip>
# include <cmath>
# include <vector>
# include <map>
# include <list>
# include <algorithm>
# include <exception>
# include <deque>
class RPN
{
	public:
		RPN();
		RPN(const RPN& newObj);
		RPN& operator=(const RPN& newObj);
		~RPN();
};

#endif
