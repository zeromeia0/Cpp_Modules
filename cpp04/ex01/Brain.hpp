/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 12:44:33 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/12/23 00:24:11 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <iomanip>
# include <cmath>

class Brain
{
	protected:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain& newObj);
		Brain& operator=(const Brain& newObj);
		~Brain();

		std::string getIdea(int i) const;
		void setIdea(int i, std::string idea);
};

#endif
