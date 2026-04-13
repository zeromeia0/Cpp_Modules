/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:58:43 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/04/13 16:52:22 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
{
	std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(std::string name, std::string target, int signGrade, int execGrade) 
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    (void)target;
	(void)_signGrade;
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
    std::cout << "AForm parametric constructor called" << std::endl;
}

AForm::AForm(const AForm& other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _signGrade(other._signGrade),
      _execGrade(other._execGrade)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& newObj)
{
    std::cout << "AForm copy assignment operator called" << std::endl;
    if (this != &newObj)
    {
        this->_name = newObj._name;
        this->_isSigned = newObj._isSigned;
        this->_signGrade = newObj._signGrade;
        this->_execGrade = newObj._execGrade;
    }
    return *this;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Formed not signed\n");
}

std::string AForm::getName() const
{
	return (_name);
}

void AForm::checkExecution(Bureaucrat const & executor) const {
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _execGrade)
        throw GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat& bureau)
{
    if (bureau.getGrade() > _signGrade)
        throw GradeTooLowException();
	if (_isSigned)
		throw alreadySignedException();
    _isSigned = true;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}
