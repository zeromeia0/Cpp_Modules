/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:59:02 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/03/20 10:44:54 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", target, 145, 137), _target(target)
{
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& newObj) : AForm(newObj)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = newObj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& newObj)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &newObj)
    {
        AForm::operator=(newObj);
        this->_target = newObj._target;
    }
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    checkExecution(executor);
    std::ofstream file((this->_target + "_shrubbery").c_str());
    if (!file.is_open())
        throw std::runtime_error("cannot open file");

    file << "          .     .  .      +     .      .          ." << std::endl;
    file << "     .       .      .     #       .           ." << std::endl;
    file << "        .      .         ###            .      .      ." << std::endl;
    file << "      .      .   \"#:. .:##\"##:. .:#\"  .      ." << std::endl;
    file << "          .      . \"####\"###\"####\"  ." << std::endl;
    file << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       ." << std::endl;
    file << "  .             \"#########\"#########\"        .        ." << std::endl;
    file << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       ." << std::endl;
    file << "     .     .  \"#######\"\"##\"##\"\"#######\"                  ." << std::endl;
    file << "                .\"##\"#####\"#####\"##\"           .      ." << std::endl;
    file << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     ." << std::endl;
    file << "      .     \"#######\"##\"#####\"##\"#######\"      .     ." << std::endl;
    file << "    .    .     \"#####\"\"#######\"\"#####\"    .      ." << std::endl;
    file << "            .     \"      000      \"    .     ." << std::endl;
    file << "       .         .   .   000     .        .       ." << std::endl;
    file << ".. .. ..................O000O........................ ......" << std::endl;

    file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}
