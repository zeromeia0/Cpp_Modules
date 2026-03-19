/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:58:47 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/03/19 13:58:48 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <iomanip>
# include <cmath>

class AForm
{
	public:
		AForm();
		AForm(const AForm& newObj);
		AForm& operator=(const AForm& newObj);
		~AForm();
};

#endif
