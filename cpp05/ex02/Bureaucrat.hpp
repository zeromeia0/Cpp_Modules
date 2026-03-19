/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:58:51 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/03/19 13:58:52 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <iomanip>
# include <cmath>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& newObj);
		Bureaucrat& operator=(const Bureaucrat& newObj);
		~Bureaucrat();
};

#endif
