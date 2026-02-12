/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:51:29 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/02/12 22:32:08 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& newObj)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = newObj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& newObj)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &newObj)
		*this = newObj;
	return (*this);
}

int Bureaucrat::getGrade()
{
	return (_grade);
}

std::string Bureaucrat::getName()
{
	return (_name);
}

void Bureaucrat::decrementGrade(int n)
{
	if (this->_grade + n > 150)
		std::cout << "salve\n"; // Colocar aqui cenas ;
	else
		_grade += n;
}

void  Bureaucrat::incrementGrade(int n)
{
	if (this->_grade - n <= 0)
		std::cout << "Burro do krl\n";
	else
		_grade -= n;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}
