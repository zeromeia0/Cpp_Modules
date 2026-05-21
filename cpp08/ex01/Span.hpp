/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:06:31 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/05/21 09:32:05 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <iomanip>
# include <cmath>
# include <vector>
# include <map>
# include <list>
# include <algorithm>
# include <exception>
# include <deque>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;
	public:
		Span();
		Span(unsigned int integers);
		Span(const Span& newObj);
		Span& operator=(const Span& newObj);
		~Span();
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		template <typename Iterator>
		void addInRange(Iterator first, Iterator last)
		{
			for (; first != last; ++first)
			{
				if (_numbers.size() >= _maxSize)
					throw (std::length_error("Container is full"));
				_numbers.push_back(*first); // at the end
			}
		}
};

#endif
