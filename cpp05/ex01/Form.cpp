/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 22:53:23 by vvazzs            #+#    #+#             */
/*   Updated: 2026/03/19 13:47:00 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _signGrade(70), _execGrade(69)
{
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(std::string newName, bool newIsSigned, int newSignGrade, int newExecGrade)
{
	this->_name = newName;
	this->_isSigned = newIsSigned;
	this->_signGrade = newSignGrade;
	this->_execGrade = newExecGrade;
	if (_signGrade < 1 || _execGrade < 1)
		throw (Form::GradeTooHighException());
	if (_execGrade > 150 || _signGrade > 150)
		throw(Form::GradeTooHLowException());

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
	return ("Form Grade is too High!\n");
}

const char* Form::GradeTooHLowException::what() const throw()
{
	return ("Form Grade is too High!\n");
}
std::string Form::getName() const
{
	return (this->_name);
}

int Form::getExecGrade() const
{
	return (this->_execGrade);
}

int Form::getSignGrade() const
{
	return (this->_signGrade);
}

int Form::getSignedBool() const
{
	return (this->_isSigned);
}

void Form::beSigned(const Bureaucrat& bureau)
{
	std::cout << "Form be signed function called\n";
	if (_signGrade < bureau.getGrade())
		throw (Form::GradeTooHLowException());
	_isSigned = true;
}
Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Form& value)
{
	out << value.getName() << " sign grade is: " << value.getSignGrade() << " and exec grade is: " << value.getExecGrade() << std::endl;
	return (out);
}