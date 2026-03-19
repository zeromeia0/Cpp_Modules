/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:58:47 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/03/19 15:47:00 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <iomanip>
# include <cmath>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const AForm& newObj);
		AForm& operator=(const AForm& newObj);
		~AForm();

		virtual void execute(Bureaucrat const & executor) const = 0;
		void checkExecution(Bureaucrat const & executor) const;
};

#endif
