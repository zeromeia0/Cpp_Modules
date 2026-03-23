/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 22:53:23 by vvazzs            #+#    #+#             */
/*   Updated: 2026/03/23 16:07:56 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _signGrade(70), _execGrade(69)
{
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(const Form& newObj) : 
	_name(newObj._name), _isSigned(newObj._isSigned),
	_signGrade(newObj._signGrade), _execGrade(newObj._execGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = newObj;
}

Form& Form::operator=(const Form& newObj)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &newObj)
		this->_isSigned = newObj._isSigned;
	return (*this);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form Grade is too high!");
}

const char* Form::GradeTooHLowException::what() const throw()
{
	return ("Form Grade is too low!");
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}
