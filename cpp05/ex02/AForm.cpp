/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:58:43 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/03/20 10:40:08 by vvazzs           ###   ########.fr       */
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
    (void)target; // If AForm doesn't have a _target member, void it or add one
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
    std::cout << "AForm parametric constructor called" << std::endl;
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
        this->_isSigned = newObj._isSigned;
    return (*this);
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

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}
