/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:58:43 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/03/19 13:58:44 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"

AForm::AForm()
{
	std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(const AForm& newObj)
{
	std::cout << "AForm copy constructor called" << std::endl;
	*this = newObj;
}

AForm& AForm::operator=(const AForm& newObj)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &newObj)
		*this = newObj;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}
