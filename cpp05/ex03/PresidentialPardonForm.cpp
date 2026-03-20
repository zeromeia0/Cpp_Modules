/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:58:54 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/03/20 10:44:37 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", target, 25, 5), _target("Default target")
{
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& newObj) : AForm(newObj)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = newObj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& newObj)
{
    std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
    if (this != &newObj)
    {
        AForm::operator=(newObj);
        this->_target = newObj._target;
    }
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    checkExecution(executor);

    std::cout << _target << " has been pardoned by the holy form\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}
