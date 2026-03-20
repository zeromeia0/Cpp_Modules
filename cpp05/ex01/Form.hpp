/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 22:53:25 by vvazzs            #+#    #+#             */
/*   Updated: 2026/03/20 09:10:11 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <iomanip>
# include <cmath>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string _name;
		bool _isSigned;
		int _signGrade;
		int _execGrade;
	public:
		Form();
		Form(std::string newName, bool newIsSigned, int newSignGrade, int newExecGrade);
		Form(const Form& newObj);
		Form& operator=(const Form& newObj);
		~Form();
		
		int getSignGrade() const;
		int  getExecGrade() const;
		int getSignedBool() const;
		std::string getName() const;
		void beSigned(const Bureaucrat& bureau);
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooHLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator <<(std::ostream& out, const Form& value);

#endif
