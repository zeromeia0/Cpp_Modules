/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:51:29 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/03/31 13:30:27 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(67)
{
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string newName, int newGrade) : _name(newName)
{
	if (newGrade < HIGHEST_POSSIBLE)
		throw GradeTooHighException();
	if (newGrade > LOWEST_POSSIBLE)
		throw GradeTooLowException();
	this->_grade = newGrade;
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
	{
		this->_grade = newObj._grade;
	}
	return (*this);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

void Bureaucrat::decrementGrade(int n)
{
	if (this->_grade + n > 150)
		throw GradeTooLowException();
	_grade += n;
}

void  Bureaucrat::incrementGrade(int n)
{
	if (this->_grade - n < HIGHEST_POSSIBLE)
		throw GradeTooHighException();
	_grade -= n;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& value)
{
	out << value.getName() << ", bureaucrat grade " << value.getGrade() << std::endl;
	return (out);
}