/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 14:21:46 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/10/09 13:44:23 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <iomanip>
# include <cmath>
#include <stack>
# include <vector>
# include <map>
# include <list>
# include <algorithm>
# include <exception>
# include <deque>
#include <climits>
#include <stdexcept>

class RPN
{
	private:
		std::string _rpnInput;
		std::stack<int> _numbers;
	public:
		RPN();
		RPN(std::string input);
		RPN(const RPN& newObj);
		RPN& operator=(const RPN& newObj);
		~RPN();
		void parseInput();
		void calculate();
};

#endif
