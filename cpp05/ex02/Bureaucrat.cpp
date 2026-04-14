/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:58:49 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/04/14 16:57:00 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
		this->_grade = newObj._grade;
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
	return ("Bureaucrat Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat Grade is too low!");
}

void Bureaucrat::signForm(AForm &form)
{
	std::cout << "Bureau signForm called\n";
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << _name << " couldn't sign " << form.getName() << " because " << e.what() << '\n';
	}
}

void Bureaucrat::executeForm(AForm const & form) const {
    try {
        form.execute(*this);
        std::cout << _name << " executed [" << form.getName() << "]" << std::endl;
    } catch (std::exception & e) {
        std::cout << _name << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}
