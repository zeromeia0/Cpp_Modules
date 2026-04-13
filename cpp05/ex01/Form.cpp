/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 22:53:23 by vvazzs            #+#    #+#             */
/*   Updated: 2026/04/13 17:00:04 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _signGrade(70), _execGrade(69)
{
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(std::string newName, bool newIsSigned, int newSignGrade, int newExecGrade)
    : _name(newName), _isSigned(newIsSigned),
      _signGrade(newSignGrade), _execGrade(newExecGrade)
{
    if (newSignGrade < 1 || newExecGrade < 1)
        throw GradeTooHighException();
    if (newSignGrade > 150 || newExecGrade > 150)
        throw GradeTooLowException();
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
	return ("[Form Grade is too high!]");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("[Form Grade is too low!]");
}

const char* Form::alreadySignedException::what() const throw()
{
	return ("[Form already signed]");
}

std::string Form::getName() const
{
    return _name;
}

int Form::getSignGrade() const
{
    return _signGrade;
}

int Form::getExecGrade() const
{
    return _execGrade;
}

int Form::getSignedBool() const
{
    return _isSigned;
}

void Form::beSigned(const Bureaucrat& bureau)
{
    if (bureau.getGrade() > _signGrade)
        {throw GradeTooLowException();}
	if (_isSigned == true)
		throw alreadySignedException();
    _isSigned = true;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Form& value)
{
    std::string isItSigned = value.getSignedBool() ? "true" : "false";

    out << value.getName()
        << ", sign grade: " << value.getSignGrade()
        << ", exec grade: " << value.getExecGrade()
        << ", signed: " << isItSigned
        << std::endl;

    return (out);
}