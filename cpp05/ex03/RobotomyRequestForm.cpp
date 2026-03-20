/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:58:58 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/03/20 10:44:51 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
	AForm("RobotomyRequestForm", target, 72, 45), _target(target)
{
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& newObj) : AForm(newObj)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = newObj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& newObj)
{
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &newObj)
    {
        AForm::operator=(newObj);
        this->_target = newObj._target;
    }
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkExecution(executor);
	std::cout << "* drilling noises *\n";
    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully\n";
    else
        std::cout << "Robotomy failed\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}
